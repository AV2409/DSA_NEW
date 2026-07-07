class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int amt, vector<int>& coins) {
        
        if (i == 0) {
            if (amt % coins[0] == 0)
                return amt / coins[0];
            else
                return 1e9;
        }
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int np = f(i - 1, amt, coins);
        int p = INT_MAX;
        if (coins[i] <= amt) {
            p = 1 + f(i, amt - coins[i], coins);
        }

        return dp[i][amt] = min(np, p);
    }
    int numSquares(int n) {
        vector<int>sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        int x=sq.size();
        dp.assign(x, vector<int>(n + 1, -1));
        return f(x-1,n,sq);
    }
};