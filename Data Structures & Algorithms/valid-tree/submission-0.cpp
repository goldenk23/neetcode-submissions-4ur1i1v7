class Solution {
public:
bool connected(vector<vector<int>>&graph,int root,int n){
    vector<int>visited(n,0);
    queue<int>q;
    q.push(root);
    visited[root]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:graph[node]){
            if(!visited[child]){
                visited[child]=1;
                q.push(child);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            return false;
        }
    }
    return true;
}
bool cyclic(vector<vector<int>>&graph,int root,int n){
    vector<int>visited(n,0);
    vector<int>parent(n,-1);
    queue<int>q;
    q.push(root);
    visited[root]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:graph[node]){
            if(visited[child]&&parent[node]!=child){return true;}
            if(!visited[child]){
            visited[child]=1;
            parent[child]=node;
            q.push(child);
            }
        }
    }
    return false;
}
    bool validTree(int n, vector<vector<int>>& edges) {
        // A valid tree is defined as connected,acyclic and undirected graph
        vector<vector<int>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        if(connected(graph,0,n)&&!cyclic(graph,0,n)){
            return true;
        }
        return false;
    }
};
