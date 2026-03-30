class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
      vector<pair<int,double>>v;
      for(int i=0;i<n;i++){
        double time=(double)(target-position[i])/speed[i];
        v.push_back({position[i],time});
      }
      sort(v.begin(),v.end());
      int fleet=0;
      double max_time=-1;
      for(int i=n-1;i>=0;i--){
        double time=v[i].second;
        if(time>max_time){
            fleet++;
            max_time=time;
        } 
      }
      return fleet;
    }
};
