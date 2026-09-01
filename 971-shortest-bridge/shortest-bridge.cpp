class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> newGrid;
    int n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    void dfs(int x, int y, vector<vector<int>>& grid, int id) {
        vis[x][y] = 1;
        newGrid[x][y] = id;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1 &&
                vis[nx][ny] == 0) {
                dfs(nx, ny, grid, id);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        vis.assign(n, vector<int>(n, 0));
        newGrid = grid;
        int id = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, id);
                    id++;
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (newGrid[i][j] == 1)
                    q.push({i, j});
            }
            cout << endl;
        }
        int ans = 0;
        while (!q.empty()) {
            int ss = q.size();
            for (int i = 0; i < ss; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if(newGrid[nx][ny]==0){
                            q.push({nx,ny});
                            newGrid[nx][ny]=1;
                        }
                        else if(newGrid[nx][ny]==2) return ans;
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};