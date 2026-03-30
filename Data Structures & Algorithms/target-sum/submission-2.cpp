class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int total = 0;
        for (auto it : nums) total += it;

        if (abs(target) > total || (total + target) % 2 != 0) {
            return 0;
        }

        int sum1 = (target + total) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum1 + 1, 0));

        // ✅ Proper base cases
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        // ✅ DP transition
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum1];
    }
};


