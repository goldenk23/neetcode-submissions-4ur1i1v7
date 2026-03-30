class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int max_till_i=nums[0];
        int min_till_i=nums[0];
        ans=max(ans,nums[0]);
        for(int i=1;i<nums.size();i++){
            int temp=max_till_i;
            max_till_i=max(nums[i],max(max_till_i*nums[i],min_till_i*nums[i]));
            min_till_i=min(nums[i],min(temp*nums[i],min_till_i*nums[i]));
            ans=max(ans,max_till_i);
        }
        return ans;
    }
};
