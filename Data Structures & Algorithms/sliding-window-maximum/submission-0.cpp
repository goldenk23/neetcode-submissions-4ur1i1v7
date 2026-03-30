class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        vector<int>ans;
        int left=0;
        int right=k-1;
       for(int right=0;right<nums.size();right++){
        if(right<k){
            st.insert(nums[right]);
            if(right==k-1){ans.push_back(*st.rbegin());}
        }else{
            st.insert(nums[right]);
            st.erase(st.find(nums[left]));
            left++;
            ans.push_back(*st.rbegin());
        }
       }
       return ans;
    }
};
