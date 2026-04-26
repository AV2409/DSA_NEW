class Solution {
public:
    int f(int pt, int lane, vector<int>& obstacles,vector<vector<int>>&dp) {
        if (pt >= obstacles.size() - 1)
            return 0;
            
        if(dp[pt][lane]!=-1) return dp[pt][lane];
        if (obstacles[pt + 1] != lane)
            return dp[pt][lane]= f(pt + 1, lane, obstacles,dp);
        int op2 = 1e9;
        for (int i = 1; i <= 3; i++) {
            if (i == lane)
                continue;
            
            if(obstacles[pt]!=i) op2 = min(op2, 1 + f(pt, i, obstacles,dp));
        }

        return dp[pt][lane]= op2;
    }
    int minSideJumps(vector<int>& obstacles) { 
        int n=obstacles.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(0, 2, obstacles,dp); 
        }
};