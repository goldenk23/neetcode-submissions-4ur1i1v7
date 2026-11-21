class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string lengths="";
        string concat="";
        for(auto it:strs){
            concat+=it;
            lengths+=to_string((int)it.length())+"*";
        }
        return concat+lengths+to_string((int)concat.length());
    }
    queue<int>get_lengths(string s){
        int i=s.length()-1;
        while(s[i]!='*'){
            i--;
        }
        string temp=s.substr(i+1);
        int j = stoi(temp);
        queue<int>lengths;
        string curr="";
        while(j<=i){
            if(s[j]=='*'){
                lengths.push(stoi(curr));
                curr="";
            }else{
                curr+=s[j];
            }
            j++;
        }
        return lengths;
    }
    vector<string> decode(string s) {
        if(s==""){
            return {};
        }
        vector<string>ans;
        queue<int>lengths=get_lengths(s);
        int i=0;
        string temp="";
        while(!lengths.empty()){
            int curr_length=lengths.front();
           // temp+=to_string(curr_length)+"*";
            lengths.pop();
            if(curr_length==0){
                ans.push_back("");
            }else{
                ans.push_back(s.substr(i,curr_length));
                i+=curr_length;
            }
        }
        return ans;
    }
};
