class DSU{
public:
    vector<int>par;
    vector<int>size;
    int n;
    DSU(int _n){
        n=_n;
        size.assign(n,1);
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }

    int findPar(int u){
        if(par[u]==u) return u;
        return par[u]=findPar(par[u]);
    }

    void unite(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]) swap(pu,pv);

        size[pu]+=size[pv];
        par[pv]=pu;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<string>names(n);
        unordered_map<string,int>mp;
        DSU dsu(n);

        for(int i=0;i<n;i++){
            int ss=accounts[i].size();
            names[i]=accounts[i][0];

            for(int j=1;j<ss;j++){
                string mail=accounts[i][j];
                if(mp.count(mail)){
                    dsu.unite(i,mp[mail]);
                }
                else mp[mail]=i;
            }
        }

        vector<set<string>>temp(n);
        for(auto it:mp){
            int idx=it.second;
            string mail=it.first;

            idx=dsu.findPar(idx);
            temp[idx].insert(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            vector<string>tt;
            if(temp[i].size()>0) {
                tt.push_back(names[i]);
                for(auto mail:temp[i]) tt.push_back(mail);
                ans.push_back(tt);
            }
        }
        return ans;
    }
};