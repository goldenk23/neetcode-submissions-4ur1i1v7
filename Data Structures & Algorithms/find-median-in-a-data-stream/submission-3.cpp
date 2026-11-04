class MedianFinder {
    priority_queue<int>left_half;
    priority_queue<int,vector<int>,greater<int>>right_half;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_half.empty()){
            left_half.push(num);
            return;
        }
        if((!right_half.empty()) && num>right_half.top()){
            right_half.push(num);
        }else{
            left_half.push(num);
        }
        if(left_half.size()>right_half.size()+1){
            right_half.push(left_half.top());
            left_half.pop();
        }
        if(right_half.size()>left_half.size()){
            left_half.push(right_half.top());
            right_half.pop();
        }
    }
    
    double findMedian() {
        if(left_half.size()==right_half.size()){
            return ((left_half.top()+right_half.top())/2.0);
        }
        return double(left_half.top());
    }
};
