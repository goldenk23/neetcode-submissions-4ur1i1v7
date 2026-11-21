class Solution {
public:
    bool canJump(vector<int>& nums) {
        int inherited_jump_prev=0;
        for(int i=1;i<(int)nums.size();i++){
            if((max(inherited_jump_prev,nums[i-1]))){
                inherited_jump_prev=max(inherited_jump_prev,nums[i-1])-1;
            }else{
                return false;
            }
        }
        return true;
    }
};
