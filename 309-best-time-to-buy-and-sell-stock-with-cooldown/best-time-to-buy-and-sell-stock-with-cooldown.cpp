class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i,vector<int>& prices,int canBuy){
        if(i>=n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];

        if(canBuy){
            //buy
            int op1=-prices[i]+f(i+1,prices,0);

            //skip
            int op2=f(i+1,prices,1);
            return dp[i][canBuy]= max(op1,op2);
        }
        else{
            //sell
            int op1=prices[i]+f(i+2,prices,1);

            //skip
            int op2=f(i+1,prices,0);
            return dp[i][canBuy]= max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return f(0,prices,1);
    }
};