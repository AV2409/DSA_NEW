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

        vector<vector<int>>dist(k+2,vector<int>(n,1e9));;
        dist[0][src]=0;

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        // {dist,node,stops}
        pq.push({0,src,0});

        while(!pq.empty()){
            auto [d,node,st]=pq.top();
            pq.pop();
            if (d > dist[st][node]) continue;
            for(auto [nei,wt]:adj[node]){
                if( st<k+1 && wt+d<dist[st+1][nei]){
                    dist[st+1][nei]=wt+d;
                    pq.push({dist[st+1][nei], nei, st+1});
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<k+2;i++){
            ans=min(ans,dist[i][dst]);
        }
        if(ans==1e9) return -1;
        return ans;
    }
};