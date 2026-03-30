class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(n1+n2!=n3){return false;}
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1));
        /*
        dp[i][j]=can we contruct first i+j elements of s3 by interleaving first i elements
        of s1 and first j elements of s2
        */
        for(int i=0;i<n1+1;i++){
                for(int j=0;j<n2+1;j++){
                        if(i==0&&j==0){dp[i][j]=true;continue;}
                        if((i>=1)&&(s3[i+j-1]==s1[i-1])){
                                dp[i][j]=dp[i-1][j];
                        }else if((j>=1)&&s3[i+j-1]==s2[j-1]){
                                dp[i][j]=dp[i][j-1];
                        }else{
                                dp[i][j]=false;
                        }
                }
        }
        return dp[n1][n2];
    }
};
