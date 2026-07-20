class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;

    int f(int i,bool bought,int trans,int k,vector<int>& prices){
        if(i==n) return 0;
        if(trans>=k) return 0;
        if(dp[i][bought][trans]!=-1) return dp[i][bought][trans];
        if(bought){
            //sell
            int op1=prices[i]+f(i+1,false,trans+1,k,prices);

            //skip
            int op2=f(i+1,bought,trans,k,prices);

            return dp[i][bought][trans]= max(op1,op2);
        }
        //buy
        int op1=-prices[i]+f(i+1,true,trans,k,prices);
        int op2=f(i+1,bought,trans,k,prices);

        return dp[i][bought][trans]= max(op1,op2);
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return f(0,false,0,k,prices);
    }
};