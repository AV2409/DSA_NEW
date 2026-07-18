class DSU {
public:
    vector<int> par;
    vector<int> size;
    int n;
    DSU(int _n) {
        n = _n;
        par.resize(_n);
        size.assign(_n, 1);
        for (int i = 0; i < _n; i++)
            par[i] = i;
    }

    void unite(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        par[pv] = pu;
        size[pu] += size[pv];
    }

    int findPar(int u) {
        if (u == par[u])
            return u;

        return par[u] = findPar(par[u]);
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        queue<pair<int, int>> q;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                if (grid[i][j] == 0)
                    q.push({i, j});
                else {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                            grid[nx][ny]) {
                            dsu.unite(id, nx * n + ny);
                        }
                    }
                }
            }
        }
        int ans = *max_element(dsu.size.begin(),dsu.size.end());
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            set<int> pars;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny]) {
                    pars.insert(dsu.findPar(nx*n+ny));
                }
            }
            int cnt=0;
            for(int p:pars){
                cnt+=dsu.size[p];
            }
            ans=max(ans,cnt+1);
        }
        return ans;
    }
};