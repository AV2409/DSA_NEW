class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int f(int i,int idx,vector<vector<int>>& piles, int k){
        if(k==0) return 0;
        if(i==n) return 0;
        if (dp[i][idx][k] != -1)
            return dp[i][idx][k];

        int np=f(i+1,0,piles,k);
        int p=0;
        if(idx<piles[i].size()){
            p=piles[i][idx]+f(i,idx+1,piles,k-1);
        }
        return dp[i][idx][k] = max(p,np);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();

        int maxPileSize = 0;
        for (auto &pile : piles)
            maxPileSize = max(maxPileSize, (int)pile.size());

        dp.assign(n, vector<vector<int>>(
            maxPileSize + 1,
            vector<int>(k + 1, -1)
        ));
        return f(0,0,piles,k);
    }
};