class Solution {
public:
    int m;
    int n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void dfs(int x, int y, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {
        vis[x][y] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                heights[nx][ny] >= heights[x][y] && !vis[nx][ny]) {
                dfs(nx, ny, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {

            dfs(0, i, heights, p);
        }
        for (int i = 0; i < m; i++) {

            dfs(i, 0, heights, p);
        }

        for (int i = 0; i < n; i++) {

            dfs(m - 1, i, heights, a);
        }
        for (int i = 0; i < m; i++) {

            dfs(i, n - 1, heights, a);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};