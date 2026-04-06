class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> q;
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        vector<vector<int>> ans = image;
        q.push({sr, sc});
        ans[sr][sc] = color;
        vis[sr][sc]=1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int prev = image[x][y];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] &&
                    image[nx][ny] == prev) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    ans[nx][ny] = color;
                }
            }
        }
        return ans;
    }
};