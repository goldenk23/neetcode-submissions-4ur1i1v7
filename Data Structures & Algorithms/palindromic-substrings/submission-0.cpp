class Solution {
public:
    int countSubstrings(string s) {
     int n=s.length();
     vector<vector<bool>>dp(n,vector<bool>(n,false));
     //dp[i][j]= is substring from i to j is a palindrome
     int ans=0;
     for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(s[i]==s[j]&&(((j-i)<=2)||dp[i+1][j-1])){
                dp[i][j]=true;
                ans++;
            }
        }
     }
     return ans;
    }
};
