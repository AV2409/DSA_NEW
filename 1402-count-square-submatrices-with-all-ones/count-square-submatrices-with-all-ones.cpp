class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        int sq = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    curr[j] = 1 + min({prev[j], prev[j - 1], curr[j - 1]});
                    sq += curr[j];
                }
            }
            prev = curr;
            curr = vector<int>(m + 1, 0);
        }

        return sq;
    }
};