class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){return 0;}
        int n=s.length();
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i-1]=='0'){
                if(s[i]=='0'){return 0;}
                dp[i]=dp[i-1];
                continue;
            }
            int num=(s[i-1]-'0')*10 + (s[i]-'0');
            if(0<num && num<=26){
                if(s[i]!='0'){
                    dp[i]=dp[i-1]+(((i-2) >= 0)?dp[i-2]:1);
                }else{
                    dp[i]=((i-2) >= 0)?dp[i-2]:1;
                }
            }else{
                if(s[i]=='0'){return 0;}
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};
