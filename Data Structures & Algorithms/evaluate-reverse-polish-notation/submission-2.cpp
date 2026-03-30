class Solution {
public:
    int operation(int a,int b,string op){
      if(op=="+"){return b+a;}
      if(op=="*"){return b*a;}
      if(op=="-"){return b-a;}
      if(op=="/"){return b/a;}
      return -1;
    }
    int evalRPN(vector<string>& tokens) {
      int ans=0;
      stack<int>st;
      for(int i=0;i<tokens.size();i++){
          string s=tokens[i];
          if(s=="+"||s=="*"||s=="-"||s=="/"){
            int num1=st.top();
            st.pop();
            int num2=st.top();
            st.pop();
            st.push(operation(num1,num2,s));
          }else{
            st.push(stoi(s));
          }
      }
      return st.top();
    }
};
