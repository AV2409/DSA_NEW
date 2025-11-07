class Solution {
public:
    void helper(vector<vector<int>>& mat, int& cnt, int x, int y, int dir,
                int m, int n) {
        // directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // boundary + wall + guard check
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] != -1 &&
            mat[nx][ny] != 1) {

            if (mat[nx][ny] == 0) { // if not guarded yet
                mat[nx][ny] = 2;   // mark guarded
                cnt++;
            }
            helper(mat, cnt, nx, ny, dir, m, n);
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0)); // 0=empty, 1=guard, -1=wall, 2=guarded
        int cnt = 0;
        vector<pair<int, int>> zz;

        // Place guards
        for (auto &it : guards) {
            int x = it[0], y = it[1];
            mat[x][y] = 1;
            cnt++;
            zz.push_back({x, y});
        }

        // Place walls
        for (auto &it : walls) {
            int x = it[0], y = it[1];
            mat[x][y] = -1;
            cnt++;
        }

        // Mark guarded cells
        for (auto [x, y] : zz) {
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] != -1 &&
                    mat[nx][ny] != 1) {
                    if (mat[nx][ny] == 0) {
                        mat[nx][ny] = 2;
                        cnt++;
                    }
                    helper(mat, cnt, nx, ny, dir, m, n);
                }
            }
        }

        return m * n - cnt;
    }
};
