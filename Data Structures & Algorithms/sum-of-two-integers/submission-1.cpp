class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        for(int i=0;i<32;i++){
            int ai=(a&(1<<i)?1:0);
            int bi=(b&(1<<i)?1:0);
            int total=(ai+bi+carry);
            int sum=(total%2);
            carry=(total/2);
            // update ith bit of ans with sum
            if(sum==1){
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};
