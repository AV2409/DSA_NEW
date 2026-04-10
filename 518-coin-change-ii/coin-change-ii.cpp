class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        const long long MOD= 1e18+7;
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {

                long long np = dp[i - 1][j];
                long long p = 0;

                if (coins[i - 1] <= j) {
                    p = dp[i][j - coins[i - 1]];
                }

                dp[i][j] = (np + p)%MOD;
            }
        }

        return (int)dp[n][amount];
    }
};