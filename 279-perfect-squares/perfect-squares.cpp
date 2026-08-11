class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(i<0) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=1e9;
        if(amount>=coins[i]) pick=1+f(i,coins,amount-coins[i]);
        int np=f(i-1,coins,amount);
        return dp[i][amount]= min(pick,np);
    }
    int numSquares(int n) {
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        int nn=nums.size();
        dp.assign(nn,vector<int>(n+1,-1));
        int ans = f(nn-1,nums,n);
        if(ans==1e9) return -1;
        return ans;
    }
};