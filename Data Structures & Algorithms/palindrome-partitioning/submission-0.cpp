class Solution {
    vector<vector<string>>ans;
public:
    vector<vector<string>> partition(string s) {
        palindrome_partitioning(s,0,{});
        return ans;
    }
    void palindrome_partitioning(string& s,int indx,vector<string> palindromes){
        if(indx==s.length()){
            ans.push_back(palindromes);
            return;
        }
        if(indx>s.length()){
            return;
        }
    for(int i=indx;i<s.length();i++){
        if(check_palindrome(s,indx,i)){
        palindromes.push_back(s.substr(indx,i-indx+1));
        palindrome_partitioning(s,i+1,palindromes);
        palindromes.pop_back();
        }
    }   
    }
    bool check_palindrome(string& s,int start,int end){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};
