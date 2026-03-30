class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();//Total n houses are there
      vector<int>dp(n+1,0);//zero based indexing
      //dp[i]=maximum money that can be robbed till i'th house
      dp[1]=nums[0];//Rob house 1 for maximum money initially 
      for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
      }
      return dp[n];
    }
};
