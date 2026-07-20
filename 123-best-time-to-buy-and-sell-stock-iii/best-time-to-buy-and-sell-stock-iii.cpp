class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;

    int f(int i,bool bought,int trans,vector<int>& prices){
        if(i==n) return 0;
        if(trans>=2) return 0;
        if(dp[i][bought][trans]!=-1) return dp[i][bought][trans];
        if(bought){
            //sell
            int op1=prices[i]+f(i+1,false,trans+1,prices);

            //skip
            int op2=f(i+1,bought,trans,prices);

            return dp[i][bought][trans]= max(op1,op2);
        }
        //buy
        int op1=-prices[i]+f(i+1,true,trans,prices);
        int op2=f(i+1,bought,trans,prices);

        return dp[i][bought][trans]= max(op1,op2);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,false,0,prices);
    }
};