class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i, int canBuy, vector<int>& prices) {
        if (i >= n)
            return 0;

        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        if (canBuy) {
            // buy
            int op1 = -prices[i] + f(i + 1, 0, prices);
            // nobuy
            int op2 = f(i + 1, 1, prices);

            return dp[i][canBuy]= max(op1, op2);
        }

        // sell
        int op1 = prices[i] + f(i + 2, 1, prices);

        // notsell
        int op2 = f(i + 1, 0, prices);
        return dp[i][canBuy]= max(op1, op2);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n,vector<int>(2,-1));
        return f(0, 1, prices);
    }
};