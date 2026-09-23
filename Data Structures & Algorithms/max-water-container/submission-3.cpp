class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;
        int max_water = 0;
        while (left < right) {
            max_water = max(max_water, min(heights[right], heights[left]) * (right - left));
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_water;
    }
};
