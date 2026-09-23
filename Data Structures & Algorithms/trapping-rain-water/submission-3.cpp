class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> highest_right(n);
        int highest = 0;
        for (int i = n - 1; i >= 0; i--) {
            highest_right[i] = highest;
            highest = max(highest, height[i]);
        }
        int highest_left = 0;
        int total_water = 0;
        for (int i = 0; i < n; i++) {
            total_water += max(0, (min(highest_left, highest_right[i]) - height[i]));
            highest_left = max(highest_left, height[i]);
        }
        return total_water;
    }
};
