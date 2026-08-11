class Solution {
public:
    vector<int>dp;
    int f(int n,int k){
        if(n==0){
            if(k==1) return 0;
            return 1;
        }
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=1;
        for(int i=1;i<=n;i++){
            int temp=i*f(n-i,k+1);
            ans=max(ans,temp);
        }
        return dp[n]= ans;
    }
    int integerBreak(int n) {
        dp.assign(n+1,-1);
        return f(n,0);
        
    }
};