class Solution {
public:
    int ans=0;
    vector<vector<pair<int,int>>>adj;

    int dfs(int node){
        int temp=0;
        int x=0;
        for(auto [nei,wt]:adj[node]){
            temp=max(temp,dfs(nei));
            x=wt;
        }
        return temp+x;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for(int i=0;i<n;i++){
            int man=manager[i];
            int emp=i;
            if(man!=-1){
                adj[man].push_back({i,informTime[man]});
            }
        }
        return dfs(headID);
    }
};