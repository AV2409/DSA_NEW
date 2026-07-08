class Solution {
public:
    vector<vector<int>>dp;
    bool f(int i, int j,string &s) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = f(i + 1, j - 1,s);
    }
    int countSubstrings(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(i,j,s)) cnt++;
            }
        }
        return cnt;
    }
};