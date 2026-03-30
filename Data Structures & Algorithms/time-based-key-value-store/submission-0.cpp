class TimeMap {
    public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].emplace_back(timestamp,value);
//emblace_back is good to pushing complex object as it construct object inside vector
//rather than creating copy of it  
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){return "";}
        string ans="";
        int left=0;
        int right=mp[key].size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(mp[key][mid].first==timestamp){return mp[key][mid].second;}
            if(mp[key][mid].first>timestamp){
                right=mid-1;
            }else{
                ans=mp[key][mid].second;
                left=mid+1;
            }  
        }
        return ans;
    }
};
