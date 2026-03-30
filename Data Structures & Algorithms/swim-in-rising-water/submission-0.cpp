class Solution {
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int ans=INT_MAX;
    vector<vector<int>>visited;
public:
void dfs(vector<vector<int>>&grid,int x, int y,int maxi){
    if(x==grid.size()-1&&y==grid[0].size()-1){
        ans=min(ans,maxi);
        return;
    }
    for(auto it:dir){
        int new_x=x+it.first;
        int new_y=y+it.second;
        if(0<=new_x&&new_x<grid.size()&&0<=new_y&&new_y<grid[0].size()
        &&!visited[new_x][new_y]){
            visited[new_x][new_y]=1;
            int x=max(maxi,grid[new_x][new_y]);
            dfs(grid,new_x,new_y,x);
            visited[new_x][new_y]=0;
        }
    }
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        visited.resize(n,vector<int>(m,0));
        visited[0][0]=1;
        dfs(grid,0,0,grid[0][0]);
        return ans;  
    }
};
