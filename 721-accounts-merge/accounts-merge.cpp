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
        unordered_map<string, int> emails;
        int n = accounts.size();
        vector<string> names(n);
        DisjointSet dsu(n);
        for (int i = 0; i < n; i++) {
            int ss = accounts[i].size();
            names[i] = accounts[i][0];
            for (int j = 1; j < ss; j++) {
                string mail = accounts[i][j];
                if (emails.count(mail)) {
                    dsu.unite(i, emails[mail]);
                } else
                    emails[mail] = i;
            }
        }
        unordered_map<int, set<string>> merged;
        for (auto& it : emails) {
            string mail = it.first;
            int idx = it.second;
            int parent = dsu.find(idx);
            merged[parent].insert(mail);
        }
        vector<vector<string>>ans;
        for(auto it:merged){
            int idx=it.first;
            vector<string>temp;
            temp.push_back(names[idx]);
            for(auto mm:it.second){
                temp.push_back(mm);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};