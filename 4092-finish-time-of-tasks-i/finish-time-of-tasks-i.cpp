class Solution {
public: 
    long long ans=0;
    vector<int> topoSort(int V, vector<vector<int>>& adj,vector<int> &indegree) {
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return topo;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        
        vector<int> indegree(n, 0);
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>topo=topoSort(n,adj,indegree);
        reverse(topo.begin(),topo.end());
        vector<long long> finish(n);
        for(int i=0;i<n;i++){
            int node=topo[i];
            if(adj[node].size()==0){
                finish[node] = baseTime[node];
                continue;
            }
            long long earliest = LLONG_MAX;
            long long latest = LLONG_MIN;

            for(int child : adj[node]) {
                earliest = min(earliest, finish[child]);
                latest = max(latest, finish[child]);
            }

            long long ownDuration = (latest - earliest) + baseTime[node];
            finish[node] = latest + ownDuration;
        }
        return finish[0];
    }
};