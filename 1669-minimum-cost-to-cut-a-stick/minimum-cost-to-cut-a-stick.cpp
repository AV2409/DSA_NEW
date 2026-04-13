class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j <= m - 1; j++) {
                int temp = 1e9;
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k] + dp[k][j] +(cuts[j] - cuts[i]);
                    temp = min(cost, temp);
                }
                dp[i][j] = temp;
            }
        }
        return dp[0][m - 1];
    }
};