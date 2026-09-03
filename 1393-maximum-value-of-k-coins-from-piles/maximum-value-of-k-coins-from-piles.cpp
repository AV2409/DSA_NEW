class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int i, int k, vector<vector<int>>& piles) {
        if (i == n || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = f(i + 1, k, piles);  // take 0 from this pile
        int sum = 0;
        for (int j = 0; j < piles[i].size() && j < k; j++) {
            sum += piles[i][j];
            ans = max(ans,sum + f(i+1,k-j-1,piles));
        }

        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();

        dp.assign(n, vector<int>(k + 1, -1));

        return f(0, k, piles);
    }
};