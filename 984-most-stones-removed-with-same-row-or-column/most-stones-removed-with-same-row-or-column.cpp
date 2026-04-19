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
    int removeStones(vector<vector<int>>& stones) {
        int maxR=0;
        int maxC=0;
        for(auto it:stones){
            maxR=max(maxR,it[0]);
            maxC=max(maxC,it[1]);
        }

        DSU dsu(maxR+maxC+2);
        unordered_set<int>st;
        for(auto it:stones){
            int r=it[0];
            int c=maxR+it[1]+1;
            dsu.unite(r,c);
            st.insert(r);
            st.insert(c);
        }
        int comps=0;
        for(int x:st){
            if(dsu.find(x)==x) comps++;
        }
        return stones.size()-comps;
    }
};