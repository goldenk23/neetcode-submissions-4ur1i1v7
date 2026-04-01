class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
      vector<pair<int,int>>window(26,{INT_MAX,INT_MIN});
      for(int i=0;i<n;i++){
        window[s[i]-'a'].first=min(window[s[i]-'a'].first,i);
        window[s[i]-'a'].second=max(window[s[i]-'a'].second,i);
      }
      vector<int>ans;
      for(int i=0;i<n;){
        int left=window[s[i]-'a'].first;
        int right=window[s[i]-'a'].second;
        int j=left+1;
        while(j<=right){
            right=max(right,window[s[j]-'a'].second);
            j++;
        }
        ans.push_back(right-left+1);
         i=j;
      }
      return ans;
    }
};
