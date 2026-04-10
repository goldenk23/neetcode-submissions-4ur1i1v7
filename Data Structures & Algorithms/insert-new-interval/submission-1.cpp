class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int s=newInterval[0];
        int e=newInterval[1];
        bool is_s_located=false;
         bool flag=true;
        for(int i=0;i<intervals.size();i++){
            int s_i=intervals[i][0];
            int e_i=intervals[i][1];
          if(e_i<s){
            ans.push_back({s_i,e_i});
            continue;
          }
        if(e<s_i){
            if(flag){ans.push_back({s,e});flag=false;}
            ans.push_back({s_i,e_i});
            continue;
        }
        s=min(s,s_i);
        e=max(e,e_i);
        }
        if(flag){ans.push_back({s,e});}
        return ans;
    }
};
