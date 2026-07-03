class DSU {
public:
    int n;
    vector<int> size;
    vector<int> parent;
    DSU(int _n) {
        n = _n+1;
        size.assign(n,1);
        parent.assign(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int paru = findUParent(u);
        int parv = findUParent(v);

        if (paru == parv)
            return;
        if (size[paru] < size[parv]) {
            swap(paru, parv);
        }

        parent[parv] = paru;
        size[paru] += size[parv];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(dsu.findUParent(u)==dsu.findUParent(v)) return edge;
            else dsu.unionBySize(u,v);
        }
        return {};
    }
};