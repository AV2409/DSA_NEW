class Solution {
public:
    
    vector<vector<vector<int>>>dp;
    bool f(int i, int j, int turn, vector<int>& piles,int alice,int bob) {
        if (i > j) {
            return alice > bob;
        }
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        if (turn == 0) {
            bool op1 = f(i + 1, j, 1 - turn, piles,alice+piles[i],bob);
            bool op2 = f(i, j - 1, 1 - turn, piles,alice+piles[j],bob);
            return dp[i][j][turn]= op1 || op2;
        }

        bool op1 = f(i + 1, j, 1 - turn, piles,alice,bob+piles[i]);
        bool op2 = f(i, j - 1, 1 - turn, piles,alice,bob+piles[j]);
        return dp[i][j][turn]= op1 || op2;
    }

    bool stoneGame(vector<int>& piles) {
        return true;
    }
};