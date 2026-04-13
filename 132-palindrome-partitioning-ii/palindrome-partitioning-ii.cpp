class Solution {
public:
    bool isPal(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int mini = 2000;
            for (int j = i; j < n; j++) {
                if (isPal(i, j, s)) {
                    int cc = 1 + dp[j + 1];
                    mini = min(cc, mini);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};