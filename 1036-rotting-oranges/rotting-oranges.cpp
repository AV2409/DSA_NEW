class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int f = 0;
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    f++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int time = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (f > 0 && !q.empty()) {
            int ss = q.size();

            for (int i = 0; i < ss; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        f--;
                    }
                }
            }
            time++;
        }
        if(f) return -1;
        return time;
    }
};