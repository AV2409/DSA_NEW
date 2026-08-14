class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>removed;

    void dfs(int node){
        removed[node]=1;
        vis[node]=1;

        for(auto nei:adj[node]){
            if(!vis[nei]){
                dfs(nei);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        adj.resize(n);
        vis.assign(n,0);
        removed.assign(n,0);
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }

        dfs(k);
        
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            if(removed[v]==1 && removed[u]==0) {
                vector<int>all;
                for(int i=0;i<n;i++){
                    all.push_back(i);
                }
                return all;
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!removed[i]) ans.push_back(i);
        }
        return ans;


    }
};