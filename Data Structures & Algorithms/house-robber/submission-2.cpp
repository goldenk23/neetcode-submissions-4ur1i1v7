class Solution {
   public:
    int rob(vector<int>& nums) {
        int prev_robbed = 0;
        int prev_skipped = 0;
        for (int i = 0; i < nums.size(); i++) {
            int max_robbed = prev_skipped + nums[i];
            int max_skipped = max(prev_robbed, prev_skipped);
            prev_robbed = max_robbed;
            prev_skipped = max_skipped;
        }
        return max(prev_robbed, prev_skipped);
    }
};
