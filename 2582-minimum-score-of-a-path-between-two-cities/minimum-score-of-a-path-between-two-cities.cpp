class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int>dist(n+1,1e9);
        dist[1]=1e9;
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>pq;

        pq.push({1e9,1});
        while(!pq.empty()){
            auto[mini,node]=pq.top();
            pq.pop();

            for(auto [nei,wt]:adj[node]){
                int newMini=min(wt,mini);
                if(newMini<dist[nei]){
                    pq.push({newMini,nei});
                    dist[nei]=newMini;
                }
            }
        }
        return dist[n];

    }
};