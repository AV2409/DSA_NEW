class Solution {
public:
    void dfs(int node,vector<int> &path,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        path.push_back(node);

        for(int nei:adj[node]){
            if(!vis[nei]){
                dfs(nei,path,adj,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            vector<int>path;
            if(!vis[i]){
                dfs(i,path,adj,vis);
                int numNodes=path.size();
                bool flag=true;
                for(int x:path){
                    if(adj[x].size()!=numNodes-1) {
                        flag=false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};