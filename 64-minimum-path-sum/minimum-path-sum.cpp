class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[0][0];
                else {
                    int u = 1e9;
                    int l = 1e9;

                    if (i > 0)
                        u = dp[i - 1][j];
                    if (j > 0)
                        l = dp[i][j - 1];

                    dp[i][j] = grid[i][j] + min(u, l);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};