class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
            swap(ulp_u, ulp_v);
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
};

class Solution {
public:
    // minimize max value of a path
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        DSU dsu(n * n);
        for (int t = 0; t < n * n; t++) {
            auto [x, y] = pos[t];
            vis[x][y] = 1;
            int id = x * n + y;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny]) {
                    dsu.unite(id, nx * n + ny);
                }
            }

            if (dsu.find(0) == dsu.find(n * n - 1))
                return t;
        }
        return -1;
    }
};