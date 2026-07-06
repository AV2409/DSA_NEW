class Solution {
public:
    int f(int n,vector<int>& sq,vector<int>& dp){
        if(n==0) return 0;
        if(n<0) return 1e9;
        if(dp[n]!=-1) return dp[n];
        int ans=1e9;
        for(int i=0;i<sq.size();i++){
            int op=1+f(n-sq[i],sq,dp);
            if(op!=1e9) ans=min(ans,op);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>sq;
        vector<int>dp(n+1,-1);
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        return f(n,sq,dp);
    }
};