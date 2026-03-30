class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                q.push({{i,j},0});
            }
        }
    }
    while(!q.empty()){
        int curr_x=q.front().first.first;
        int curr_y=q.front().first.second;
        int curr_length=q.front().second;
        q.pop();
        for(auto it:dir){
            int new_x=curr_x+it.first;
            int new_y=curr_y+it.second;
            if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&(curr_length+1)<grid[new_x][new_y]){
                grid[new_x][new_y]=curr_length+1;
                q.push({{new_x,new_y},curr_length+1});
            }
        }
    }
    }
};
