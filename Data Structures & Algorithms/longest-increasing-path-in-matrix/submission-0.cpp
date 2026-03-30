class Solution {
    vector<pair<int,int>>dir={{-1,0},{0,1},{0,-1},{1,0}};
    void solve(vector<vector<int>>&matrix,int i,int j, int length,vector<vector<int>>&dp){
        if(dp[i][j]>length){return;}
        dp[i][j]=length;
        for(auto it:dir){
            int x=i+it.first;
            int y=j+it.second;
            if(0<=x&&x<matrix.size()&&0<=y&&y<matrix[0].size()){
                if(matrix[x][y]>matrix[i][j]){
                    solve(matrix,x,y,length+1,dp);
                }
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
       //dp[i][i]=length of longest increasing path till cell (i,j);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            solve(matrix,i,j,1,dp);
        }
       }
       int ans=INT_MIN;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,dp[i][j]);
        }
       }
       return ans; 
    }
};
