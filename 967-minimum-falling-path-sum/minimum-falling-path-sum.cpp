class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        dp[1][1] = matrix[0][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1) {
                    dp[i][j] = matrix[i - 1][j - 1];
                    continue;
                }
                int x1=1e9;
                if(j<n) x1=dp[i - 1][j + 1] + matrix[i - 1][j - 1];
                dp[i][j] = min({dp[i - 1][j] + matrix[i - 1][j - 1],
                               dp[i - 1][j - 1] + matrix[i - 1][j - 1],
                               x1});
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m][i]);
        }
        return ans;
    }
};