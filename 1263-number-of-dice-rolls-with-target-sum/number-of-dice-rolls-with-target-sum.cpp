class Solution {
public:
    
    const int MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        for (int ii = 1; ii <= n; ii++) {
            for (int j = 1; j <= target; j++) {
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (j - i >= 0)
                        ans =((ans % MOD) + (dp[ii - 1][j - i] % MOD)) % MOD;
                }
                dp[ii][j] = ans;
            }
        }
        return dp[n][target];
    }
};