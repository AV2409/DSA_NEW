class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
        if (fresh == 0)
            return 0;

        vector<int>dx={0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        int ans = 0;
        while (!q.empty() && fresh > 0) {
            int s = q.size();
            ans++;
            for (int i = 0; i < s; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]==1){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        fresh--;
                    }
                }
            }
        }

        if(fresh==0) return ans;
        return -1;
    }
};