class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    int area=0;
                    visited[i][j]=1;
                    q.push({{i,j},1});
                    while(!q.empty()){
                        int curr_x=q.front().first.first;
                        int curr_y=q.front().first.second;
                        int curr_length=q.front().second;
                        q.pop();
                        area++;
                        ans=max(ans,area);
                        for(auto it:dir){
                            int new_x=curr_x + it.first;
                            int new_y=curr_y + it.second;
                            if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&grid[new_x][new_y]==1&&
                            !visited[new_x][new_y]){
                                visited[new_x][new_y]=1;
                                q.push({{new_x,new_y},curr_length+1});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
