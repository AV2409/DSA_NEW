class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> rowMax(
            n, vector<vector<int>>(m, vector<int>(m)));
        for (int row = 0; row < n; row++) {
            for (int l = 0; l < m; l++) {
                int mx = 0;
                for (int r = l; r < m; r++) {
                    mx = max(mx, matrix[row][r]);
                    rowMax[row][l][r] = mx;
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > 0)
                    q.push({i, j});
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int x = matrix[r][c];

            int rs = max(0, r - x);
            int re = min(n - 1, r + x);

            int cs = max(0, c - x);
            int ce = min(m - 1, c + x);
            bool flag = true;
            for (int i = rs; i <= re; i++) {
                int ele = 0;
                if (i == r - x || i == r + x) {
                    bool leftCornerExists = (c - x >= 0);
                    bool rightCornerExists = (c + x < m);

                    if (leftCornerExists && rightCornerExists) {
                        if (cs + 1 <= ce - 1)
                            ele = rowMax[i][cs + 1][ce - 1];
                        else
                            ele = 0;
                    } else if (leftCornerExists) {
                        if (cs + 1 <= ce)
                            ele = rowMax[i][cs + 1][ce];
                    } else if (rightCornerExists) {
                        if (cs <= ce - 1)
                            ele = rowMax[i][cs][ce - 1];
                    } else {
                        ele = rowMax[i][cs][ce];
                    }
                } else {
                    ele = rowMax[i][cs][ce];
                }

                if (ele > x) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
};