class Solution {
public:
    int maxArea(vector<int>& heights) {
       int left=0;
       int right=heights.size()-1;
       int area=INT_MIN;
       while(left<right){
        area=max(area,(right-left)*min(heights[left],heights[right]));
        // move the pointer with less height, moving pointer with more height can
        // not result more area than now  in the next move 
        if(heights[left]<=heights[right]){left++;}
        else if(heights[right]<=heights[left]){right--;}
       } 
       return area;
    }
};
