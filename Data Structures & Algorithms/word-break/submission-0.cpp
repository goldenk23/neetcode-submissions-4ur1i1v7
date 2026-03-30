class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string>wordset;// hasing of words in wordDict so lookup becomes o(1)
       for(auto it:wordDict){
        wordset.insert(it);
       }
       int n=s.length();
       vector<bool>dp(n);
       //dp[i]=is it possible to segment till i 
       for(int i=0;i<n;i++){
        if(wordset.count(s.substr(0,i+1))){
            dp[i]=true;
            continue;
        }
        bool is_done=false;
        for(int j=i-1;j>=0;j--){
            if(dp[j]&& wordset.count(s.substr(j+1,i-j))){
                dp[i]=true;
                is_done=true;
                break;
            }
        }
        if(!is_done){dp[i]=false;}
       }
       return dp[n-1];
    }
};
