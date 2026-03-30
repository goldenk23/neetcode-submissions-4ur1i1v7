class Solution {
    unordered_map<char,vector<char>>mp;
    vector<string>ans;
public:
void preprocess(){
    char cr='a';
  for(char i='2';i<='9';i++){
    int count=0;
    int temp=3;
    if(i=='7'||i=='9'){temp=4;}
    for(;cr<='z'&&(count<temp);cr++,count++){
        mp[i].push_back(cr);
    }
  }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){return {};}
        preprocess();
        letter(digits,0,"");
      return ans;
    }
    void letter(string& digits,int indx,string combination){
        if(indx==digits.length()){
            ans.push_back(combination);
            return;
        }
        if(indx>digits.length()){
            return;
        }
        for(auto it:mp[digits[indx]]){
            combination.push_back(it);
            letter(digits,indx+1,combination);
            combination.pop_back();
        }
    }
};
