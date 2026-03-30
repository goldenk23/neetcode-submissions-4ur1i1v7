class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        logic:
        sum1-sum2=target;
        sum1+sum2=total;
        2*sum1=(target+total)
        sum1=(target+total)/2;
        now problem boils down to in how many ways we can build sum1 from num
        */
        int n=nums.size();
        int total=0;
        for(auto it:nums){
            total+=it;
        }
        if(abs(target)>total || (total+target)%2!=0){
            return 0;
        }
        int sum1=(target+total)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum1+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum1+1;j++){
              if(i==0){
                if(j!=0){dp[i][j]=0;}
                continue;
              }
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum1];
    }
};

