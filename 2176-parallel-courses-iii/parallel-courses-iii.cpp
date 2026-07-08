class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>inDeg(n+1);
        for(auto it:relations){
            int u=it[0];
            int v=it[1];
            inDeg[v]++;
            adj[u].push_back(v);
        }
        int ans=0;
        vector<int>finishTime(n+1,0);
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(inDeg[i]==0){
                q.push(i);
                finishTime[i]=time[i-1];
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int t=finishTime[node];
            ans=max(ans,t);

            for(int nei:adj[node]){
                inDeg[nei]--;
                finishTime[nei]=max(finishTime[nei],t+time[nei-1]);
                if(inDeg[nei]==0){
                    q.push(nei);
                    ans=max(ans,finishTime[nei]);
                }
            }
        }
        return ans;
    }
};