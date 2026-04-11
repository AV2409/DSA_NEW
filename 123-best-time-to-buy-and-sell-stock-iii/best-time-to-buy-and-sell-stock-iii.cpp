class Solution {
public:
//buy=1 -->can buy
//buy=0--> not buy
    int f(int i, int buy, int trans, int n, vector<int>& prices,vector<vector<vector<int>>> &dp) {
        if(i==n) return 0;
        if(trans==2) return 0;

        if(dp[i][trans][buy]!=-1) return dp[i][trans][buy];
        if(buy){
            int op1=f(i+1,1,trans,n,prices,dp);
            int op2=-prices[i]+f(i+1,0,trans,n,prices,dp);
            return dp[i][trans][buy]=max(op1,op2);
        }
        else{
            int op1=f(i+1,0,trans,n,prices,dp);
            int op2=+prices[i]+f(i+1,1,trans+1,n,prices,dp);
            return dp[i][trans][buy]=max(op1,op2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(3, vector<int>(2,-1)));
        
        return f(0, 1, 0, n, prices, dp);
    }
};