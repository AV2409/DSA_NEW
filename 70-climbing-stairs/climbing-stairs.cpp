class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int op1 = dp[i - 1];
            int op2 = 0;
            if (i > 1) {
                op2 = dp[i - 2];
            }
            dp[i] = op1 + op2;
        }
        return dp[n];
    }
};