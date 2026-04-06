class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr_sub_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sub_sum+=nums[i];
            curr_sub_sum=max(curr_sub_sum,nums[i]);
            ans=max(ans,curr_sub_sum);
        }
        return ans;
    }
};
