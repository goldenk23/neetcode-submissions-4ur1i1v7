class Solution {
    vector<string>ans;
public:
    vector<string> generateParenthesis(int n) {
        generate_parentheses(n,0,0,"");
        return ans;
    }
    void generate_parentheses(int n,int opening,int closing,string parentheses){
        if(opening==n&&closing==n){
            ans.push_back(parentheses);
            return;
        }
        if(opening<n){
        parentheses.push_back('(');
        generate_parentheses(n,opening+1,closing,parentheses);
        parentheses.pop_back();
        }
        if((closing<n)&&(opening>closing)){
            parentheses.push_back(')');
            generate_parentheses(n,opening,closing+1,parentheses);
            parentheses.pop_back();
        }
    }
};
