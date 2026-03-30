class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>max_heap;
        for(int i=0;i<stones.size();i++){
            max_heap.push(stones[i]);
        }
      while(max_heap.size()>1){
        int stone1=max_heap.top();
        max_heap.pop();
        int stone2=max_heap.top();
        max_heap.pop();
        if(stone1!=stone2){
            max_heap.push(stone1-stone2);
        }
      }
      return max_heap.size()==1?max_heap.top():0;
    }
};
