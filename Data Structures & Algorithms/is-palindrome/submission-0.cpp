class Solution {
public:
    bool isPalindrome(string s) {
      int left=0;
      int right=s.length()-1;
      while(left<=right){
        if(!(('A'<=s[left]&&s[left]<='Z')
       ||('a'<=s[left]&&s[left]<='z')
        ||('0'<=s[left]&&s[left]<='9')))
        {
            left++;
        }
        else if(!(('A'<=s[right]&&s[right]<='Z')
        ||('a'<=s[right]&&s[right]<='z')
        ||('0'<=s[right]&&s[right]<='9')))
        {
            right--;
        }else
        {
            if(toupper(s[left])==toupper(s[right]))
            {
                left++;
                right--;
            }else
            {
              return false;  
            }
        }
      }
      return true;  
    }
};
