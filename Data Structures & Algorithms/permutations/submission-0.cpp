class Solution {
vector<vector<int>>ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        generate_permutation(nums,{},{});
        return ans; 
    }
    void generate_permutation(vector<int>&nums,set<int>st,vector<int>permutation){
      if(st.size()==nums.size()){
        ans.push_back(permutation);
        return;
      }
      for(int i=0;i<nums.size();i++){
        if(st.find(nums[i])==st.end()){
            permutation.push_back(nums[i]);
            st.insert(nums[i]);
            generate_permutation(nums,st,permutation);
            st.erase(nums[i]);
            permutation.pop_back();
        }
      }
    }
};
