class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       vector<vector<int>>ans;
       for(auto it:intervals){
        int s_i=it[0];
        int e_i=it[1];
        if(ans.empty()){
            ans.push_back({s_i,e_i});
            continue;
        }
        if(ans.back()[1]<s_i){
            ans.push_back({s_i,e_i});
            continue;
        }
        ans.back()[0]=min(ans.back()[0],s_i);
        ans.back()[1]=max(ans.back()[1],e_i);
       }
       return ans; 
    }
};
