class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>st;
      int ans=0;
      for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
      }
   for(int i=0;i<nums.size();i++){
    if(st.count(nums[i]-1)==0){
        int len=0;
        while(st.count(nums[i]++)){
            len++;
        }
        ans=max(ans,len);
    }
   }
   return ans;
    }
};
