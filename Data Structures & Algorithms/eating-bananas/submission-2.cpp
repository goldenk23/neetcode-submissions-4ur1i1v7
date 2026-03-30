class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(is_possible(piles,h,mid)){
                ans=min(ans,mid);
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
    bool is_possible(vector<int>&v,int& h, int&k){
        int time=0;
        for(int i=0;i<v.size();i++){
            time+=(v[i]+k-1)/k;// adding ceil of (v[i]/k) i.e how much time it takes to complete this pile 
        }
        return time<=h?true:false;
    }
};
