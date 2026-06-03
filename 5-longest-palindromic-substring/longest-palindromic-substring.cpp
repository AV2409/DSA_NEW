class Solution {
public:
    vector<vector<int>>dp;
    bool f(string &s, int i, int j) {
        if (i >= j) return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = f(s, i + 1, j - 1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (f(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};