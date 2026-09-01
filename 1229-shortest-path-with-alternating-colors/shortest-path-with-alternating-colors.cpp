class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>dist(2*n,1e9);
        vector<vector<int>>adj(2*n);
        for(auto it:redEdges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(n+v);
        }

        for(auto it:blueEdges){
            int u=it[0];
            int v=it[1];

            adj[n+u].push_back(v);
        }

        dist[0]=0;
        dist[n]=0;

        queue<int>q;
        q.push(0);
        q.push(n);

        int d=1;
        vector<int>vis(2*n,0);
        vis[0]=1;
        vis[n]=1;
        while(!q.empty()){
            int ss=q.size();
            while(ss--){
                int node=q.front();
                q.pop();

                for(int nei:adj[node]){
                    if(!vis[nei]){
                        dist[nei]=d;
                        q.push(nei);
                        vis[nei]=1;
                    }
                }
            }
            d++;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            int x=min(dist[i],dist[i+n]);
            if(x==1e9) ans.push_back(-1);
            else ans.push_back(x);
        }
        return ans;
    }
};