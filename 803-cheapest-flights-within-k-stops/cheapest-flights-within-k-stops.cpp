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
        vector<vector<int>>dist(n,vector<int>(k+2,1e9));
        dist[src][0]=0;

        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,src});

        while(!pq.empty()){
            auto it=pq.top();
            int d=it[0];
            int stops=it[1];
            int node=it[2];
            pq.pop();
            if(node==dst) return d;
            if(stops==k+1) continue;
            if(d>dist[node][stops]) continue;

            for(auto& [adjNode,wt]:adj[node]){
                if(wt+d<dist[adjNode][stops+1]){
                    dist[adjNode][stops+1]=wt+d;
                    pq.push({d+wt,stops+1,adjNode});
                }
            }
        }
        return -1;

    }
};