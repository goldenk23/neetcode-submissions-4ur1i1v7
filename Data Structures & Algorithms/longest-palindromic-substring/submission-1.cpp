class Solution {
public:
    string longestPalindrome(string s) {
      int n=s.length();
      string s1=s;
      reverse(s1.begin(),s1.end());
      // Now longest palindromic substring will be longest common substring of s and s1
      vector<vector<int>>dp(n+1,vector<int>(n+1));
      int max_len=0;
      int end_indx=0;
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
                continue;
            }
            if(s[i-1]==s1[j-1]){
                dp[i][j]=(1+dp[i-1][j-1]);
                int original_start=i-dp[i][j];
                int reversed_start=n-j;
                if(original_start==reversed_start&&dp[i][j]>max_len){
                    max_len=dp[i][j];
                    end_indx=i;
                }
            }else{
                dp[i][j]=0;
            }
        }
        
      }
      return s.substr(end_indx-max_len, max_len);
    }
};
