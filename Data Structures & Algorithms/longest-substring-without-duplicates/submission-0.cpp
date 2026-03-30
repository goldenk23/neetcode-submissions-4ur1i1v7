class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left=0;
       int ans=0;
       unordered_map<char,int>mp;
       for(int r=0;r<s.length();r++){
        if(mp.find(s[r])!=mp.end()){
            left=max(mp[s[r]]+1,left);
        }
        mp[s[r]]=r;
        ans=max(ans,r-left+1);
       }
       return ans;
    }
};
