class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
  unordered_map<char,int>frequency;
  for(int i=0;i<tasks.size();i++){
    frequency[tasks[i]]++;
  }
  priority_queue<int>max_heap;
  for(auto it:frequency){
    max_heap.push(it.second);
  }
  int cycle=0;
  while(!max_heap.empty()){
    vector<int>temp;
    int temp_cycle=n+1;
    while(temp_cycle&&!max_heap.empty()){
        int freq=max_heap.top();
        max_heap.pop();
        freq--;
        cycle++;
        temp_cycle--;
        if(freq){temp.push_back(freq);}
     }
     if(temp_cycle&&!temp.empty()){cycle+=temp_cycle;}
     for(int i=0;i<temp.size();i++){
        max_heap.push(temp[i]);
     }
  }
  return cycle;
    }
};
