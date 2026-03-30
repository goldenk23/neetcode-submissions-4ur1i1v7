class MedianFinder {
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
     if(max_heap.empty()||num<=max_heap.top()){
        max_heap.push(num);
     }else{
        min_heap.push(num);
     }
     if(min_heap.size()+1<max_heap.size()){
        min_heap.push(max_heap.top());
        max_heap.pop();
     }else if(max_heap.size()<min_heap.size()){
        max_heap.push(min_heap.top());
        min_heap.pop();
     }
     return;
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size()){
            return (max_heap.top()+min_heap.top())/2.0;
        }
        return max_heap.top();
    }
};
