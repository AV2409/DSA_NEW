class Solution {
public:
vector<int>dp;
    int f(int n){
        if(n<=1) return 1;
        int ans=0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=n;i++){
            ans+=f(i-1)*f(n-i);
        }
        return dp[n]= ans;
    }
    int numTrees(int n) {
        dp.assign(n+1,-1);
        return f(n);
    }
};