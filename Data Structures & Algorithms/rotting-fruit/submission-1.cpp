class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int curr_x=q.front().first.first;
            int curr_y=q.front().first.second;
            int curr_time=q.front().second;
            q.pop();
            for(auto it:dir){
                int new_x=curr_x+it.first;
                int new_y=curr_y+it.second;
                if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&grid[new_x][new_y]==1&&curr_time+1<time
                [new_x][new_y]){
                    time[new_x][new_y]=curr_time+1;
                    q.push({{new_x,new_y},curr_time+1});
                }
            }
        }
        int ans=-1;
        int fresh_count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh_count++;
                    ans=max(ans,time[i][j]);
                }
            }
        }
        if(!fresh_count){return 0;}
        return ans==INT_MAX?-1:ans;
    }
};
