class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = pairs[i][0];
            for (int j = 0; j < i; j++) {
                int b = pairs[j][1];
                if (c>b) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};