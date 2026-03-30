class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();//Total n houses are there
    //   vector<int>dp(n+1,0);//zero based indexing
    //   //dp[i]=maximum money that can be robbed till i'th house
    //   dp[1]=nums[0];//Rob house 1 for maximum money initially 
    //   for(int i=2;i<=n;i++){
    //     dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
    //   }
    //   return dp[n];

    if(n==0){return 0;}
    if(n==1){return nums[0];}
    int prev2=0;// maximum profit till (i-2)'th house
    int prev1=nums[0];// maximum profit till (i-1)'th house
    for(int i=1;i<n;i++){
        int curr=max(prev1,prev2+nums[i]);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    }
};
