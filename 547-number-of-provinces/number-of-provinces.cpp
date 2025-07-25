class DisjointSet {
public:
    vector<int> parent;
    // vector<int> size;
    vector<int> rank;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        // size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v) {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // void unionBySize(int u, int v) {
    //     int ulp_u = findUParent(u);
    //     int ulp_v = findUParent(v);

    //     if (ulp_u == ulp_v) {
    //         return;
    //     }

    //     if (size[ulp_u] < size[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //         size[ulp_v] += size[ulp_u];
    //     } else {
    //         parent[ulp_v] = ulp_u;
    //         size[ulp_u] += size[ulp_v];
    //     }
    // }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                cnt++;
            }
        }
        return cnt;
    }
};