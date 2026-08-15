class Solution {
public:
    int alice = 0;
    int bob = 0;
    vector<vector<vector<int>>>dp;
    bool f(int i, int j, int turn, vector<int>& piles) {
        if (i > j) {
            return alice > bob;
        }
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        if (turn == 0) {
            alice += piles[i];
            bool op1 = f(i + 1, j, 1 - turn, piles);
            alice -= piles[i];
            alice += piles[j];
            bool op2 = f(i, j - 1, 1 - turn, piles);
            alice -= piles[j];
            return dp[i][j][turn]= op1 || op2;
        }

        bob += piles[i];
        bool op1 = f(i + 1, j, 1 - turn, piles);
        bob -= piles[i];
        bob += piles[j];
        bool op2 = f(i, j - 1, 1 - turn, piles);
        bob -= piles[j];
        return dp[i][j][turn]= op1 || op2;
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,0,piles);
    }
};