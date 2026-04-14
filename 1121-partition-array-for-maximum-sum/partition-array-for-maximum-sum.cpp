class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n-1; i >= 0; i--) {
            if (n - i <= k) {
                int maxe = arr[i];
                for (int t = i; t < n; t++) {
                    maxe = max(maxe, arr[t]);
                }
                dp[i] = (n - i) * maxe;
                continue;
            }

            int ans = 0;
            int maxe = arr[i];
            for (int t = i; t < i + k; t++) {
                maxe = max(maxe, arr[t]);
                int temp = maxe * (t - i + 1) + dp[t + 1];
                ans = max(ans, temp);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};