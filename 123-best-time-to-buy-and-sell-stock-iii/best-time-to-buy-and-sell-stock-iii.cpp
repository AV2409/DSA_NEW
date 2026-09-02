class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;

    int f(int i, int canBuy,int trans, vector<int>& prices) {
        if(trans>=2) return 0;
        if (i == n)
            return 0;

        if(dp[i][canBuy][trans]!=-1) return dp[i][canBuy][trans];
        if (canBuy) {
            // buy
            int op1 = -prices[i] + f(i + 1, 0,trans, prices);
            // nobuy
            int op2 = f(i + 1, 1,trans, prices);

            return dp[i][canBuy][trans]= max(op1, op2);
        }

        // sell
        int op1 = prices[i] + f(i + 1, 1,trans+1, prices);

        // notsell
        int op2 = f(i + 1, 0,trans, prices);
        return dp[i][canBuy][trans]= max(op1, op2);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,1,0,prices);
    }
};