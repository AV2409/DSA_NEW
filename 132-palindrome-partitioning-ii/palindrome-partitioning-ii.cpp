class Solution {
public:
    vector<int> dp;
    vector<vector<bool>> pal;
    int f(int i, string& s) {
        if (i == s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (int idx = i; idx < s.size(); idx++) {
            if (pal[i][idx]) {
                ans = min(ans, 1 + f(idx + 1, s));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        pal.assign(n, vector<bool>(n, false));

        // Length = 1
        for (int i = 0; i < n; i++)
            pal[i][i] = true;

        // Length >= 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] != s[j])
                    pal[i][j] = false;
                else if (len == 2)
                    pal[i][j] = true;
                else
                    pal[i][j] = pal[i + 1][j - 1];
            }
        }
        dp.assign(n, -1);
        return f(0, s) - 1;
    }
};