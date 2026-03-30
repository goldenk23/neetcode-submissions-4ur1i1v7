class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n=temperatures.size();
    vector<int>NGR(n,0);
    stack<int>st;
    for(int i=temperatures.size()-1;i>=0;i--){
      while(!st.empty()&&temperatures[i]>=temperatures[st.top()]){
        st.pop();
      }
      if(!st.empty()){
        NGR[i]=st.top();
      }
      st.push(i);
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
     if(NGR[i]==0){ans[i]=0;}
     else{
      ans[i]=NGR[i]-i;
     }
    }
    return ans;
    }
};
