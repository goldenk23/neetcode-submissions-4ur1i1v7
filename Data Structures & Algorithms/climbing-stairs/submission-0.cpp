class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[1]=1;//Number of ways to go to first stair is 1
        dp[2]=2;//Number of ways to go to second stair is 2(either jupm to 2 or come from 1)
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
