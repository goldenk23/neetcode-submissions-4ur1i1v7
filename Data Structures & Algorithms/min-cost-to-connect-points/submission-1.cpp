class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                graph[i+1].push_back({j+1,dist});
                graph[j+1].push_back({i+1,dist});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(n+1,0);
        pq.push({0,1});
        int mst=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]){continue;}
            visited[node]=1;
            mst+=wt;
            for(auto it:graph[node]){
                int child=it.first;
                int adj_wt=it.second;
                if(!visited[child]){
                    pq.push({adj_wt,child});
                }
            }
        }
        return mst;
    }
};
