class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<pair<int,int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&(i==0||j==0||i==n-1||j==m-1)&&board[i][j]=='O'){
                    visited[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int curr_x=q.front().first;
                        int curr_y=q.front().second;
                        q.pop();
                        for(auto it:dir){
                            int new_x=curr_x+it.first;
                            int new_y=curr_y+it.second;
                            if(0<=new_x&&new_x<n&&0<=new_y&&new_y<m&&!visited[new_x][new_y]
                            &&board[new_x][new_y]=='O'){
                                visited[new_x][new_y]=1;
                                q.push({new_x,new_y});
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
