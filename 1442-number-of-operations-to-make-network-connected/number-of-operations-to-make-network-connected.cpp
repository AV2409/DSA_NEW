class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.find(u) == ds.find(v)) {
                extraEdges++;
            } else {
                ds.unite(u, v);
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                components++;
            }
        }

        int min_req = components - 1;

        if (extraEdges >= min_req) {
            return min_req;
        } else {
            return -1;
        }
    }
};