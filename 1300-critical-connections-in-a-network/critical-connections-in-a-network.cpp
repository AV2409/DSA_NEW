class Solution {
public:
    vector<vector<int>>ans;
    vector<int>low;
    vector<int>dt;
    vector<int>vis;
    int timer=0;
    vector<vector<int>>adj;
    void dfs(int node,int par){
        timer++;
        dt[node]=timer;
        low[node]=timer;
        vis[node]=1;
        for(int adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,node);
                low[node]=min(low[node],low[adjNode]);
                if(low[adjNode]>dt[node]) ans.push_back({node,adjNode});
            }
            else{
                if(adjNode!=par){
                    low[node]=min(low[node],dt[adjNode]);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low.assign(n,0);
        dt.assign(n,0);
        vis.assign(n,0);
        adj.resize(n);

        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,-1);
        }
        
        return ans;
    }
};