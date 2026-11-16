class Solution {
    bool is_valid(vector<vector<int>>&graph,int node,int parent,vector<int>&visited){
        visited[node]=1;
        bool ans=true;
        for(auto child_node:graph[node]){
            if(child_node!=parent){
                if(visited[child_node]){
                    return false;
                }
                ans=ans&&(is_valid(graph,child_node,node,visited));
            }
        }
        return ans;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>visited(n,0);
        if(!is_valid(graph,0,-1,visited)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
