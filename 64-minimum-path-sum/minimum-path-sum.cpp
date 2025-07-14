class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 1e9);
        for (int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    curr[j] = grid[0][0];
                else {
                    int u = 1e9;
                    int l = 1e9;

                    if (i > 0)
                        u = prev[j];
                    if (j > 0)
                        l = curr[j - 1];

                    curr[j] = grid[i][j] + min(u, l);
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};