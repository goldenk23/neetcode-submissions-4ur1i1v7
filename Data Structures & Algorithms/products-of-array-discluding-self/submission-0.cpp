class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int non_zero_prod=1;
        int zero_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
            non_zero_prod*=nums[i];
            }else{
                zero_count++;
            }
        }
        for(int i=0;i<nums.size();i++){
           if(nums[i])
           {
            if(zero_count)
            {
                ans.push_back(0);
            }else{
                ans.push_back(non_zero_prod/nums[i]);
            }
           }else{
            if(zero_count>1){
              ans.push_back(0);  
            }else{
                ans.push_back(non_zero_prod);
            }
           }
        }
        return ans;
    }
};
