class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     vector<int>count1(26,0);
     for(int i=0;i<s1.length();i++){
        count1[s1[i]-'a']++;
     }
     vector<int>count2(26,0);
     int left=0;
     int right=s1.length()-1;
     for(int i=left;i<=right;i++){
        count2[s2[i]-'a']++;
     }
     while(right<s2.length()){
        if(count1==count2){return true;}
        else{
            count2[s2[left]-'a']--;
            left++;
            right++;
            count2[s2[right]-'a']++;
        }
     }
     return false;
    }
};
