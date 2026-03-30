class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0){dp[i][j]=1;continue;}//only one empty subsequence 
                if(j==0){
                    if(i==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                    continue;
                }
                if(t[i-1]==s[j-1]){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
