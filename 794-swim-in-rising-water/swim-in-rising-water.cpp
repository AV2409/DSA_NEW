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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>hash(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]={i,j};
            }
        }

        DSU dsu(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        for(int t=0;t<n*n;t++){
            auto [x,y]=hash[t];
            int og=n*x+y;
            vis[x][y]=1;

            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];
                if(nx>=0 && ny>=0 && nx<n && ny<n && vis[nx][ny]){
                    dsu.unite(og,nx*n+ny);
                }
            }
            if(dsu.findPar(0)==dsu.findPar(n*n-1)) return t;
        }
        return -1;
    }
};