// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         multiset<int>st;
//         vector<int>ans;
//         int left=0;
//         int right;
//        for( right=0;right<nums.size();right++){
//         if(right<k){
//             st.insert(nums[right]);
//             if(right==k-1){ans.push_back(*st.rbegin());}
//         }else{
//             st.insert(nums[right]);
//             st.erase(st.find(nums[left]));
//             left++;
//             ans.push_back(*st.rbegin());
//         }
//        }
//        return ans;
//     }
// };



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
         while(!dq.empty()&&dq.front()<=i-k){
            dq.pop_front();
         }
         while(!dq.empty()&&nums[dq.back()]<nums[i]){
            dq.pop_back();
         }
         dq.push_back(i);
         if(i>=k-1){ans.push_back(nums[dq.front()]);}
        }
        return ans;
    }
};
