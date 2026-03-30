class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2);
        dp[1]=0;// we can start from first stair
        dp[2]=0;// we can start from second stair
        for(int i=3;i<n+2;i++){
            dp[i]=min(dp[i-1]+cost[i-1-1],dp[i-2]+cost[i-2-1]);
        }
        return dp[n+1];
    }
};
