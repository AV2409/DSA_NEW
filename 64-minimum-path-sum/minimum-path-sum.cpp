class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = 1e9;
                int x2 = 1e9;
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i > 0)
                    x1 = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    x2 = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(x1, x2);
            }
        }
        return dp[m - 1][n - 1];
    }
};