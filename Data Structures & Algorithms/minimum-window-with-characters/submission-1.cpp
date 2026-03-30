class Solution {
public:
    string minWindow(string s, string t) {
     vector<int>count_t(128,0);
     for(int i=0;i<t.length();i++){
        count_t[t[i]]++;
     }
     vector<int>count_s(128,0);
    int left=0;
    int l=t.length();
    int matched=0;
    int length=INT_MAX;
    int lp=0,rp=0;
    for(int right=0;right<s.length();right++){
        count_s[s[right]]++;
        if(count_t[s[right]]>0&&count_s[s[right]]<=count_t[s[right]]){
            matched++;
        }
      while(matched==l){
        if(length>right-left+1){
            length=right-left+1;
            lp=left;
            rp=right;
        }
        count_s[s[left]]--;
        if(count_t[s[left]]>0&&count_s[s[left]]<count_t[s[left]]){
            matched--;
        }
        left++;
      }  
    }
    if(length==INT_MAX){return "";}
    return s.substr(lp,rp-lp+1);
    }
};

