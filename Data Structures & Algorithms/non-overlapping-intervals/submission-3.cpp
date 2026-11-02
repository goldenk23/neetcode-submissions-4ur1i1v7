class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=1;
        int prev_start=intervals[0][0];
        int prev_end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int curr_start=intervals[i][0];
            int curr_end=intervals[i][1];
            if(prev_end<=curr_start){
                count++;
                prev_start=curr_start;
                prev_end=curr_end;
            }else{
                // greedly remove interval which is extended farthest towards right
                if(prev_end>curr_end){
                    prev_start=curr_start;
                    prev_end=curr_end;
                }
            }
        }
        return (int)intervals.size()-count;
    }
};
