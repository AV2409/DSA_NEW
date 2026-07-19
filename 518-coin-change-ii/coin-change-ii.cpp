class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,vector<int>& coins,int amount){
        if(i<0) {
            if(amount==0) return 1;
            return 0;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int np=f(i-1,coins,amount);
        int p=0;
        if(amount>=coins[i]) p=f(i,coins,amount-coins[i]);

        return dp[i][amount]= p+np;
    }
    int change(int amount, vector<int>& coins) {
        // if(amount == 0) return 0;
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans=f(n-1,coins,amount);
        return ans;
    }
};