class Solution {
public:
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int>cnt(n,0);
        cnt[0]=1;
        dist[0]=0;
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d>dist[node]) continue;
            for(auto &[nei,wt]:adj[node]){
                if(wt+d<dist[nei]){
                    dist[nei]=wt+d;
                    cnt[nei]=cnt[node];
                    pq.push({wt+d,nei});
                }
                else if(wt+d==dist[nei]){
                    cnt[nei]=(cnt[nei]+cnt[node])%MOD;
                }
            }
        }

        return cnt[n-1]%MOD;
    }
};