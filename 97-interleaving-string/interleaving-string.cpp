class Solution {
public:
    vector<vector<int>> dp;
    bool f(int i, int j, string& s1, string& s2, string& s3) {
        int k=i+j+1;
        if (k < 0 && i < 0 && j < 0)
            return true;
        if (i < 0 && j < 0)
            return false;
        if (i < 0) {
            for (int x = j; x >= 0; x--) {
                if (s2[x] != s3[k--])
                    return false;
            }
            return true;
        }
        if (j < 0) {
            for (int x = i; x >= 0; x--) {
                if (s1[x] != s3[k--])
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool op1 = false;
        bool op2 = false;

        if (i >= 0 && s1[i] == s3[k])
            op1 = f(i - 1, j, s1, s2, s3);
        if (j >= 0 && s2[j] == s3[k])
            op2 = f(i, j - 1, s1, s2, s3);

        return dp[i][j]= op1||op2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();

        if (p != n + m)
            return false;
        dp.assign(n,vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, s3);
    }
};