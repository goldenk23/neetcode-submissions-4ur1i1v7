class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,0)));
      /*dp[i][j][k]
      i-> maximum profit till ith day
      j->0(not holding any stock), 1(holding the stock)
      k->1(cool dowm i.e selled on prev day), 0(no cooldown i.e not selled on prev day)
      */
      dp[0][1][0]=-prices[0];// buying stock on first day
      dp[0][0][0]=0;// not buying stock on first day
      for(int i=1;i<n;i++){
       dp[i][1][0]= max(dp[i-1][1][0], dp[i-1][0][0]-prices[i]);// Today i have a stock and i am not in cooldown
       dp[i][0][1]= max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);//Today i don't have stock and i am in cooldown(that means i sold )
       dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0]);// Today i don't have stock and neither i am in cooldown
      }
      return max(max(dp[n-1][0][1],dp[n-1][0][0]),dp[n-1][1][0]+prices[n-1]);
    }
};
