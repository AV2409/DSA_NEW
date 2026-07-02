class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Modified Dijkstra (Maximum Minimum Path)
        priority_queue<vector<int>> pq;
        vector<vector<int>> bestSafe(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});
        bestSafe[0][0] = dist[0][0];
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1)
                return safe;

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && min(safe, dist[nx][ny])>bestSafe[nx][ny]) {
                    int newSafe = min(safe, dist[nx][ny]);
                    bestSafe[nx][ny] = newSafe;
                    pq.push({newSafe, nx, ny});
                }
            }
        }

        return 0;
    }
};