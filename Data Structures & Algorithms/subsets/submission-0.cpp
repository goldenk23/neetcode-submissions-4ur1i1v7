class Solution {
    vector<vector<int>>ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        find_subsets(nums,0,{});
        return ans;    
    }
    void find_subsets(vector<int>&nums,int indx,vector<int>subset){
        if(indx>=nums.size()){
            ans.push_back(subset);
            return;
        }
        int i=indx;
        int prev=nums[indx];
        for(i;i<nums.size();i++){
            if(nums[i]!=prev){break;}
        }
        find_subsets(nums,i,subset);
        subset.push_back(nums[indx]);
        find_subsets(nums,indx+1,subset);
    }
};
