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

    int find(int u){
        if(par[u]==u) return u;
        return par[u]=find(par[u]);
    }

    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]) swap(pu,pv);

        size[pu]+=size[pv];
        par[pv]=pu;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>ans;
        int n=accounts.size();
        unordered_map<string,int>par;

        DSU dsu(n);
        for(int i=0;i<n;i++){
            int nn=accounts[i].size();
            for(int j=1;j<nn;j++){
                string mail=accounts[i][j];
                if(par.count(mail)){
                    dsu.unite(i,par[mail]);
                }
                par[mail]=i;
            }
        }
        unordered_map<int,set<string>>res;
        for(auto it:par){
            string mail=it.first;
            int i=it.second;

            int p=dsu.find(i);
            res[p].insert(mail);
        }

        for(auto it:res){
            vector<string>temp;
            int idx=it.first;
            temp.push_back(accounts[idx][0]);
            for(auto x:it.second) temp.push_back(x);
            ans.push_back(temp);
        }
        return ans;
    }
};