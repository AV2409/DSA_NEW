class DSU {
public:
    int n;
    vector<int> size;
    vector<int> parent;
    DSU(int _n) {
        n = _n;
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
    static bool comp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        DSU dsu(V);
        sort(edges.begin(),edges.end(),comp);
        int ans=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dsu.findUParent(u)!=dsu.findUParent(v)){
                ans+=wt;
                dsu.unionBySize(u,v);
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>>edges;
        for (int i = 0; i < n; i++) {
            int x1=points[i][0];
            int y1=points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x2-x1)+abs(y2-y1);
                edges.push_back({i,j,dist});
            }
        }
        return spanningTree(n,edges);
    }
};