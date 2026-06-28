class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        if (fresh == 0)
            return 0;

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        int ans = 0;

        while (!q.empty()) {
            int ss = q.size();
            for (int i = 0; i < ss; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        !vis[nx][ny] && grid[nx][ny] == 1) {
                        vis[nx][ny] = 1;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            if (!q.empty())
                ans++;
        }

        if (fresh == 0)
            return ans;
        return -1;
    }
};