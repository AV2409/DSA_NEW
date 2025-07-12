class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));
        int sq = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    ans[i][j] = 1 + min({ans[i - 1][j], ans[i - 1][j - 1],
                                         ans[i][j - 1]});
                    sq += ans[i][j];
                }
            }
        }
        return sq;
    }
};