class KthLargest {
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int size=0;
    int limit=0;
public:
    KthLargest(int k, vector<int>& nums) {
        limit=k;
        for(int i=0;i<nums.size();i++){
           min_heap.push(nums[i]);
           size++;
           if(size>limit){
            min_heap.pop();
            size--;
           }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        size++;
        if(size>limit){
            min_heap.pop();
            size--;
        }
        return min_heap.top();  
    }
};
