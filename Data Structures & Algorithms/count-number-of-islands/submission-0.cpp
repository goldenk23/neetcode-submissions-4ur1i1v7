class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>>visited(n,vector<int>(m));
      vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
      queue<pair<int,int>>q;
      int island_count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]=='1'){
                visited[i][j]=1;
                island_count++;
        q.push({i,j});
        while(!q.empty()){
            int curr_x=q.front().first;
            int curr_y=q.front().second;
            q.pop();
            for(auto it:dir){
                int new_x=curr_x+it.first;
                int new_y=curr_y+it.second;
                if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&!visited[new_x][new_y]&&grid[new_x][new_y]=='1'){
                    visited[new_x][new_y]=1;
                    q.push({new_x,new_y});
                }
            }
        }
            }

        }
      }  
      return island_count;
    }
};
