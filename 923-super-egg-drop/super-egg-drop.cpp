class Solution {
public:
    vector<vector<int>> dp;
    int f(int n, int k) {
        if (n == 1)
            return 1;
        if (n <= 0)
            return 0;
        if (k == 1)
            return n;
        if (dp[n][k] != -1)
            return dp[n][k];
        int ans = 1e9;
        int st = 1;
        int end = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            int breakCase = f(mid - 1, k - 1);
            int notBreakCase = f(n - mid, k);

            int temp = 1 + max(breakCase, notBreakCase);
            ans = min(ans, temp);

            if (breakCase < notBreakCase) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return f(n, k);
    }
};