class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>>graph(n+1);
       for(auto edges:times){
        graph[edges[0]].push_back({edges[1],edges[2]});
       }
       vector<int>time(n+1,INT_MAX);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,k});
       time[k]=0;
       while(!pq.empty()){
        int curr_time=pq.top().first;
        int curr_node=pq.top().second;
        pq.pop();
        if(curr_time>time[curr_node]){continue;}
        for(auto it:graph[curr_node]){
            int adj_node=it.first;
            int time_wt=it.second;
            if(time[curr_node]+time_wt<time[adj_node]){
                time[adj_node]=time[curr_node]+time_wt;
                pq.push({time[adj_node],adj_node});
            }
        }
       } 
       int ans=0;
       for(int i=1;i<=n;i++){
        ans=max(ans,time[i]);
       }
       return ans==INT_MAX?-1:ans;
    }
};
