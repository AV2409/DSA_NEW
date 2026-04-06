class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ones = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    ones++;
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        if (ones == 0)
            return mat;
        
        vector<int>dx={0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        vector<vector<int>>ans(m,vector<int>(n,0));
        int dist=0;
        while(!q.empty() && ones>0){
            int s = q.size();
            dist++;
            for (int i = 0; i < s; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && mat[nx][ny]==1){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        ones--;
                        ans[nx][ny]=dist;
                    }
                }
            }
        }
        return ans;

    }
};