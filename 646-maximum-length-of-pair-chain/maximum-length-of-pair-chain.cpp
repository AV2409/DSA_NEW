class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto p1 = pairs[i];
            int c = p1[0];
            int d = p1[1];
            for (int j = 0; j < i; j++) {
                auto p2 = pairs[j];
                int a = p2[0];
                int b = p2[1];
                if (c>b) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};