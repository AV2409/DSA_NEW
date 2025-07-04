class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        while (!q.empty()) {
            pair<int, pair<int, int>> p = q.top();
            q.pop();

            int eff = p.first;
            int x = p.second.first;
            int y = p.second.second;
        
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m)) {
                    int n_effort = abs(heights[x][y] - heights[nx][ny]);
                    int max_effort = max(eff, n_effort);
                    if (max_effort < dist[nx][ny]) {
                        dist[nx][ny] = max_effort;
                        q.push({max_effort, {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};