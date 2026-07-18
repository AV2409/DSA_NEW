class DSU{
public:
    vector<int>par;
    vector<int>size;
    int n;
    DSU(int _n){
        n=_n;
        par.resize(_n);
        size.assign(_n,1);
        for(int i=0;i<_n;i++) par[i]=i;
    }
    
    void unite(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            swap(pu,pv);
        }
        
        par[pv]=pu;
        size[pu]+=size[pv];
    }
    
    int findPar(int u){
        if(u==par[u]) return u;
        
        return par[u]=findPar(par[u]);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra=0;
        for(auto con:connections){
            int u=con[0];
            int v=con[1];
            if(dsu.findPar(u)==dsu.findPar(v)) extra++;
            else dsu.unite(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(dsu.findPar(i)==i) comp++;
        }
        if(extra>=comp-1) return comp-1;
        return -1;
    }
};