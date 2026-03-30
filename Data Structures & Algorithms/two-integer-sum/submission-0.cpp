class Solution {
public:
    int find_indx(vector<int>&nums,int target){
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i])){
                return {find_indx(nums,target-nums[i]),i};
            }
            st.insert(target-nums[i]);
        }
        return {};
    }

};
