class Solution {
public:
    vector<vector<int>> dp;
    int f(int st, int end) {
        if (st >= end)
            return 0;
        if (end - st == 1)
            return st;
        if (dp[st][end] != -1)
            return dp[st][end];
        int ans = INT_MAX;
        int temp = 0;
        for (int i = st; i <= end; i++) {
            int x = f(st, i - 1);
            int y = f(i + 1, end);
            temp = i + max(x, y);
            ans = min(ans, temp);
        }
        return dp[st][end] = ans;
    }
    int getMoneyAmount(int n) {
        dp.assign(n + 1, vector<int>(n + 1, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {
                if (start == end)
                    continue;
                if (end - start == 1)
                    dp[start][end] = start;
                else {
                    int ans = INT_MAX;
                    int temp = 0;
                    for (int i = start; i <= end; i++) {
                        int x = (i > start) ? dp[start][i - 1] : 0;
                        int y = (i < end) ? dp[i + 1][end] : 0;
                        temp = i + max(x, y);
                        ans = min(ans, temp);
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }
};