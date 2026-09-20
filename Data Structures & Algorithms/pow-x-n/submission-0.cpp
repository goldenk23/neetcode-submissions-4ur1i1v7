class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        double ans=1.0;
        bool is_negative=(n<0)?true:false;
        n=abs(n);
        while(n){
            if(n&1){
                ans=(ans*x);
            }
            x=(x*x);
            n=n>>1;
        }
        if(is_negative){
            return 1/ans;
        }
        return ans;
    }
};
