class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node=i*n+j;
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int adjNode = ni * n + nj;
                            dsu.unite(node, adjNode);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*n;i++){
            ans=max(ans,dsu.size[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int node=i*n+j;
                    unordered_set<int>st;
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int adjNode = ni * n + nj;
                            st.insert(dsu.find(adjNode));
                        }
                    }
                    int temp=1;
                    for(int x:st){
                        temp+=dsu.size[x];
                    }
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};