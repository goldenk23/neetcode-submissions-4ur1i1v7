class Solution {
    vector<vector<int>>ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      generate_subsets(nums,0,{});
      return ans;  
    }
    void generate_subsets(vector<int>&nums,int index,vector<int>subset){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        int i=index;
        int prev=nums[index];
        for(i;i<nums.size();i++){
            if(prev!=nums[i]){break;}
        }
        generate_subsets(nums,i,subset);
        subset.push_back(nums[index]);
        generate_subsets(nums,index+1,subset);
    }
};
