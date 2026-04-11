class Solution {
public:
// buy=1 -->can buy
    // buy=0--> not buy
    int f(int i, int buy, int n, vector<int>& prices,
          vector<vector<int>>& dp,int fee) {
        if (i >= n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy) {
            int op1 = f(i + 1, 1, n, prices, dp,fee);
            int op2 = -prices[i] + f(i + 1, 0, n, prices, dp,fee);
            return dp[i][buy] = max(op1, op2);
        } else {
            int op1 = f(i + 1, 0, n, prices, dp,fee);
            int op2 = prices[i] + f(i + 1, 1, n, prices, dp,fee)-fee;
            return dp[i][buy] = max(op1, op2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return f(0, 1, n, prices, dp,fee);
    }
};