class Solution {
  vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
public:
void bfs(queue<pair<int,int>>&q,vector<vector<int>>&h,vector<vector<int>>&v){
    int n=h.size();
    int m=h[0].size();
    while(!q.empty()){
        int curr_x=q.front().first;
        int curr_y=q.front().second;
        q.pop();
        for(auto it:dir){
            int new_x=curr_x+it.first;
            int new_y=curr_y+it.second;
            if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&!v[new_x][new_y]&&
            h[new_x][new_y]>=h[curr_x][curr_y]){
                v[new_x][new_y]=1;
                q.push({new_x,new_y});
            }
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n=heights.size();
       int m=heights[0].size();
       vector<vector<int>>atlantic(n,vector<int>(m,0));
       vector<vector<int>>pacific(n,vector<int>(m,0));
       queue<pair<int,int>>q;
       for(int i=0;i<m;i++){
        q.push({0,i});
        pacific[0][i]=1;
       }
       for(int i=0;i<n;i++){
        q.push({i,0});
        pacific[i][0]=1;
       }
       bfs(q,heights,pacific);
       for(int i=0;i<m;i++){
        q.push({n-1,i});
        atlantic[n-1][i]=1;
       }
       for(int i=0;i<n;i++){
        q.push({i,m-1});
        atlantic[i][m-1]=1;
       }
       bfs(q,heights,atlantic);
       vector<vector<int>>ans;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(atlantic[i][j]&&pacific[i][j]){
                ans.push_back({i,j});
            }
        }
       }
       return ans;
    }
};
