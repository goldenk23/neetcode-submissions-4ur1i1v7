class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int last_price=prices[0];
        for(int i=1;i<prices.size();i++){
            int curr_price=prices[i];
            profit=max(profit,(curr_price-last_price));
            last_price=min(last_price,curr_price);
        }
        return profit;
    }
};
