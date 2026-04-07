class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n+1,1e9);

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        //{stops,dist,src}
        pq.push({0,0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto [st,d,node]=pq.top();
            pq.pop();
            if(st>k) continue;
            // if(node==dst) return d;
            for(auto [nei,wt]:adj[node]){
                if(d+wt<dist[nei]){
                    dist[nei]=d+wt;
                    pq.push({st+1,dist[nei],nei});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};