class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return 0;}
        if(nums[0]>=n-1){return 1;}// jump directly to last element
        int ans=1;// jupm to first window
        int curr_left=1;
        int curr_right=nums[0];
        while(true){
            int next_left=INT_MAX;
            int next_right=INT_MIN;
            for(int i=curr_left;i<=curr_right&&(i<n);i++){
                if(i==n-1){
                    return ans;
                }
                if(i+nums[i]>=n-1){
                    return ans+1;// jump directly to the end
                }
                if(i+nums[i]>curr_right){
                    next_left=min(next_left,curr_right+1);
                    next_right=max(next_right,i+nums[i]);
                }
            }
          if(next_right<=curr_right){
            break;
          }
            curr_left=next_left;
            curr_right=next_right;
            ans++;// jump to next window
        }
        return -1;
    }
};
