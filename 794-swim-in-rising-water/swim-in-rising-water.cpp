class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({grid[0][0], 0, 0});
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto [curr, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return curr;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    max(grid[nx][ny], curr) < dist[nx][ny]) {
                    dist[nx][ny] = max(grid[nx][ny], curr);
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};