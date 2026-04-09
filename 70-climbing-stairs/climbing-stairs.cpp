class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int o1=dp[i+1];
            int o2=0;
            if(i+2<=n) o2=dp[i+2];
            dp[i]=o1+o2;
        }
        return dp[0];
    }
};