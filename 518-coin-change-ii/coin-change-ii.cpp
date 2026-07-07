class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int amt, vector<int>& coins) {
        if (i == 0) {
            if (amt % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][amt] != -1)
            return dp[i][amt];
        int np = f(i - 1, amt, coins);
        int p = 0;
        if (coins[i] <= amt) {
            p = f(i, amt - coins[i], coins);
        }

        return dp[i][amt] = p+np;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        dp.assign(n, vector<int>(amount + 1, -1));
        int x = f(n - 1, amount, coins);
        return x;
    }
};