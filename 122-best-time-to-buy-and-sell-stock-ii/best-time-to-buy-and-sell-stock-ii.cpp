class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i,bool bought,vector<int>& prices){
        if(i==n) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];
        if(bought){
            //sell
            int op1=prices[i]+f(i,false,prices);

            //skip
            int op2=f(i+1,bought,prices);

            return dp[i][bought]= max(op1,op2);
        }
        //buy
        int op1=-prices[i]+f(i+1,true,prices);
        int op2=f(i+1,bought,prices);

        return dp[i][bought]= max(op1,op2);

    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return f(0,false,prices);
    }
};