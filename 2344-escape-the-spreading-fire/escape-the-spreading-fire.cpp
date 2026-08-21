class Solution {
public:
    vector<vector<int>> fire;
    int m;
    int n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool isPossible(int mid, vector<vector<int>>& grid) {
        if (fire[0][0] <= mid)
            return false;

        queue<tuple<int, int,int>> q;
        q.push({0, 0, mid});
        vector<vector<int>> vis;
        vis.assign(m, vector<int>(n, 0));
        vis[0][0]=1;
        while (!q.empty()) {
            auto [x, y, time] = q.front();
            q.pop();
            if(x==m-1 && y==n-1) return true;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx==m-1 && ny==n-1 && grid[nx][ny] !=2 && 1+time<=fire[nx][ny]) return true;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != 2 && !vis[nx][ny] && 1+time<fire[nx][ny]) {
                    q.push({nx, ny,time+1});
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;

    }
    int maximumMinutes(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        fire.assign(m, vector<int>(n, INT_MAX));
        vector<vector<int>> vis;
        vis.assign(m, vector<int>(n, 0));
        queue<pair<int, int>> f;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    f.push({i, j});
                    fire[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        int timer = 1;

        while (!f.empty()) {
            int nn = f.size();
            for (int i = 0; i < nn; i++) {
                auto [x, y] = f.front();
                f.pop();
                

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == 0 && !vis[nx][ny]) {
                        f.push({nx, ny});
                        vis[nx][ny] = 1;
                        fire[nx][ny] = timer;
                    }
                }
            }
            timer++;
        }

        int l = 0;
        int h = 1e9;
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isPossible(mid, grid)) {
                ans = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return ans;
    }
};