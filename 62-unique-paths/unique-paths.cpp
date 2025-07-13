class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        prev[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int x1 = 0, x2 = 0;
                x1 = prev[j];
                if (j > 0)
                    x2 = curr[j - 1];
                curr[j] = x1 + x2;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};