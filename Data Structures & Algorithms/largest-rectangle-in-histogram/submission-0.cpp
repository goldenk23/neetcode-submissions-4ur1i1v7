class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);
        NSL(heights,nsl);
        NSR(heights,nsr);
        int area=-1;
        for(int i=0;i<n;i++){
                area=max(area,heights[i]*(nsr[i]-nsl[i]-1));
        }
        return area;
    }
    void NSL(vector<int>&h,vector<int>&v){
        stack<int>st;
        for(int i=0;i<h.size();i++){
            while(!st.empty()&&h[i]<=h[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(i);
        }
    }
    void NSR(vector<int>&h,vector<int>&v){
        stack<int>st;
        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty()&&h[i]<=h[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                v[i]=st.top();
            }
            st.push(i);
        }
    }
};
