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
     int matched=0;
     for(int i=0;i<26;i++){
        if(count1[i]==count2[i]){
            matched++;
        }
     }

     for(right=s1.length();right<s2.length();right++){
     if(matched==26){return true;}
  int right_indx=s2[right]-'a';
  count2[right_indx]++;
  if(count2[right_indx]==count1[right_indx]){
    matched++;
  }else if(count2[right_indx]==count1[right_indx]+1){
    matched--;
  }
  int left_indx=s2[left]-'a';
  count2[left_indx]--;
  if(count2[left_indx]==count1[left_indx]){
    matched++;
  }else if(count2[left_indx]==count1[left_indx]-1){
    matched--;
  }
  left++;
     }
     return matched==26;
    }
};

