class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int curr_end=0;// end point of the current window
        int farthest=0;// end point of upcoming window
        for(int i=0;i<nums.size();i++){
            farthest=max(farthest,i+nums[i]);
            if(farthest>=n-1){return true;}
            if(i==curr_end){
                if(farthest<=curr_end){return false;}
                curr_end=farthest;
            }
        }
        return false;
    }
};
