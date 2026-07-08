class Solution {
public:
    vector<vector<int>>dp;
    bool f(int i, int j, string& s, string& p) {
        if (i < 0 && j < 0)
            return true;
        // s finished
        if (i < 0) {
            while (j >= 0 && p[j] == '*')
                j--;
            return j < 0;
        }
        // p finished
        if (j < 0) {
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (p[j] == '*') {
            bool op1 = f(i - 1, j - 1, s, p);
            bool op2 = f(i - 1, j, s, p);
            bool op3 = f(i, j - 1, s, p);
            return dp[i][j]= op1 || op2 || op3;
        } else if (p[j] == '?') {
            return dp[i][j]= f(i - 1, j - 1, s, p);
        }

        if (s[i] == p[j])
            return dp[i][j]= f(i - 1, j - 1, s, p);
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n,vector<int>(m,-1));
        return f(n - 1, m - 1, s, p);
    }
};