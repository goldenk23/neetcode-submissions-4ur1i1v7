class Solution {
    vector<vector<int>>ans;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     find_combination(nums,target,0,{});
     return ans;   
    }
    void find_combination(vector<int>&nums,int target,int indx,vector<int>combination){
        if(target==0){
            ans.push_back(combination);
            return;
        }
        if(target<0||indx>=nums.size()){
            return;
        }
        int i=indx;
        int prev=nums[indx];
        for(i;i<nums.size();i++){
            if(nums[i]!=prev){break;}
        }
        find_combination(nums,target,i,combination);
        combination.push_back(nums[indx]);
        find_combination(nums,target-nums[indx],indx,combination);
    }
};
