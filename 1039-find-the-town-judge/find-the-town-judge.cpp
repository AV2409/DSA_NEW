class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outDeg(n+1);
        vector<int>inDeg(n+1);
        for(auto it:trust){
            int u=it[0];
            int v=it[1];
            outDeg[u]++;
            inDeg[v]++;
        }
        for(int i=1;i<=n;i++){
            if(outDeg[i]==0 && inDeg[i]==n-1) return i;
        }
        return -1;
    }
};