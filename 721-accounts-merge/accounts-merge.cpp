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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int rows=accounts.size();
        DisjointSet ds(rows);

        for(int i=0;i<rows;i++){
            int ss=accounts[i].size();
            for(int j=1;j<ss;j++){
                if(mp.count(accounts[i][j])){
                    ds.unite(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }

        unordered_map<int,set<string>>ff;

        for(auto it:mp){
            string mail=it.first;
            int idx=it.second;
            int par=ds.find(idx);

            ff[par].insert(mail);
        }

        int x=ff.size();
        int i=0;
        vector<vector<string>>ans(x);
        for(auto it:ff){
            int idx=it.first;
            string name=accounts[idx][0];
            ans[i].push_back(name);
            for(string st:it.second) ans[i].push_back(st);
            i++;
        }

        
        return ans;
    }
};