class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(!(sum%2==0)){return false;}
        int target=sum/2;
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1));
        for(int i=0;i<nums.size()+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0){dp[i][j]=false;continue;}
                if(j==0){dp[i][j]=true;continue;}
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];
    }
};
