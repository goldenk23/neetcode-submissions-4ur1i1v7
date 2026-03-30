class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        queue<int>q;
        int ans=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
                ans++;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(!visited[it]){
                            visited[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
