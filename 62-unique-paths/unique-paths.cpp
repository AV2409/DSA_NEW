class Solution {
public:
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else {
                int u = 0, l = 0;
                if (i > 0) u = prev[j];
                if (j > 0) l = curr[j - 1];
                curr[j] = u + l;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

};