class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int amount, vector<int>& coins){
        if(amount==0) return 1;
        if(i<0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int np=f(i-1,amount,coins);
        int p=0;
        if(amount>=coins[i]) p=f(i,amount-coins[i],coins);
        return dp[i][amount]= p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins);
    }
};