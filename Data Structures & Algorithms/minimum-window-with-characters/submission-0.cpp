// class Solution {
// public:
//     string minWindow(string s, string t) {
//      vector<int>count_t(128,0);
//      for(int i=0;i<t.length();i++){
//         count_t[t[i]]++;
//      }
//      vector<int>count_s(128,0);
//     //  for(int i=0;i<s.length();i++){
//     //     count_s[s[i]]++;
//     //  }   
    
//     // for(int i=0;i<t.length();i++){
//     //     if(count_s[t[i]]<count_t[t[i]]){
//     //         return "";
//     //     }
//     // }
//     int left=0;
//     int l=t.length();
//     int matched=0;
//     int length=INT_MAX;
//     int lp=0,rp=0;
//     for(int right=0;right<s.length();right++){
//         if(count_t[s[right]]){
//             matched++;
//         }
//       while(matched>=l){
//         if(length<right-left+1){
//             length=right-left+1;
//             lp=left;
//             rp=right;
//         }
//         if(count_t[s[left]]){
//             matched--;
//         }
//         left++;
//       }  
//     }
//     if(lp==0&&rp==0){return "";}
//     return s.substr(lp,rp-lp+1);
//     }
// };



class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count_t(128,0);
        for(int i=0; i<t.length(); i++) {
            count_t[t[i]]++;
        }
        
        vector<int> count_s(128,0);
        int left = 0;
        int matched = 0; // Count of characters from t that are currently satisfied
        int length = INT_MAX;
        int lp = 0, rp = 0;
        
        for(int right = 0; right < s.length(); right++) {
            // Add current character to window
            count_s[s[right]]++;
            
            // If this character is in t and we need more of it
            if(count_t[s[right]] > 0 && count_s[s[right]] <= count_t[s[right]]) {
                matched++;
            }
            
            // Try to shrink the window from left while we have all characters
            while(matched == t.length()) {
                // Update minimum window
                if(right - left + 1 < length) {
                    length = right - left + 1;
                    lp = left;
                    rp = right;
                }
                
                // Remove left character from window
                count_s[s[left]]--;
                
                // If we removed a character from t and now don't have enough
                if(count_t[s[left]] > 0 && count_s[s[left]] < count_t[s[left]]) {
                    matched--;
                }
                
                left++;
            }
        }
        
        if(length == INT_MAX) return "";
        return s.substr(lp, rp - lp + 1);
    }
};