class Solution {
public:
    vector<pair<int,int>> find_target(vector<int>&v,int left, int right,int target){
        vector<pair<int,int>>res;
        while(left<right){
            if(v[left]+v[right]<target){left++;}
            else if(v[left]+v[right]>target){right--;}
            else{
                res.push_back({v[left],v[right]});
                int prev_left=left;
                int prev_right=right;
                left++;
                right--;
                while(v[left]==v[prev_left]&&v[right]==v[prev_right]){
                    prev_left=left;
                    prev_right=right;
                    left++;
                    right--;
                }
                }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        //unordered_map<pair<int,int>,int>st;
        int prev=1e7;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=prev){
           vector<pair<int,int>> v= find_target(nums,i+1,nums.size()-1,-nums[i]);
           for(auto it:v){
            ans.push_back({nums[i],it.first,it.second});
           }
           prev=nums[i];
            }               
        }
        return ans;
    }
};
