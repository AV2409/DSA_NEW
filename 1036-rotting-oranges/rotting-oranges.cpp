class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int f = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                if (grid[i][j] == 1) {
                    f++;
                }
            }
        }

        while (!q.empty()) {
            int s = q.size();
            bool flag = false;
            for (int i = 0; i < s; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = {0, -1, 0, 1};
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) &&
                        (grid[nx][ny] == 1) && (!visited[nx][ny])) {
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                        grid[nx][ny] = 2;
                        f--;
                        flag = true;
                    }
                }
            }
            if (flag)
                t++;
        }
        if (f == 0) {
            return t;
        } else {
            return -1;
        }
    }
};