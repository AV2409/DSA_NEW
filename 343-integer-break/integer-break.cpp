class Solution {
public:
    vector<int> dp;

    int f(int n) {
        if(n == 1) return 1;
        if(dp[n] != -1)
            return dp[n];

        int ans = 0;

        for(int i = 1; i < n; i++) {
            ans = max({ans, i * f(n-i),i*(n-i)});
        }
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        dp.assign(n+1, -1);
        return f(n);
    }
};