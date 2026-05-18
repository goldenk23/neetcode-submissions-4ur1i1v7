class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>merged;
        sort(nums.begin(),nums.end());
        int prev_start=nums[0][0];
        int prev_end=nums[0][1];
        for(int i=1;i<nums.size();i++){
            int start = nums[i][0];
            int end = nums[i][1];
            if(prev_end<start){
                merged.push_back({prev_start,prev_end});
                // start new interval
                prev_start=start;
                prev_end=end;
            }else{
                prev_start = min(start,prev_start);
                prev_end = max(end, prev_end);
            }
        }
        merged.push_back({prev_start, prev_end});
       return merged;
    }
};
