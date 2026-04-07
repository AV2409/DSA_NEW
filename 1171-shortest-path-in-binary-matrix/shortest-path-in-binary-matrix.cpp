class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;
        vector<int> dx = {0, 0, -1, 1, 1, 1, -1, -1};
        vector<int> dy = {-1, 1, 0, 0, 1, -1, 1, -1};
        q.push({0, 0});
        int ans = 0;
        while (!q.empty()) {
            int s = q.size();
            ans++;
            for (int i = 0; i < s; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return ans;

                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return -1;
    }
};