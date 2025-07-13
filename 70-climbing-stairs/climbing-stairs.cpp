class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n == 0)
            return dp[n] = 1;

        if (dp[n] != -1) {
            return dp[n];
        }
        int op1 = f(n - 1, dp);
        int op2 = 0;
        if (n > 1) {
            op2 = f(n - 2, dp);
        }
        return dp[n] = op1 + op2;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};