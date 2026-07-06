class Solution {
public:
    vector<int>dp;
    int f(int i, string s) {
        if (i < 0)
            return 1;
        
        if(dp[i]!=-1) return dp[i];
        int op1 = 0;
        int op2 = 0;

        int nn=s[i]-'0';
        if(nn>=1 && nn<=9){
            op1 = f(i - 1, s);
        }

        if (i - 1 >= 0) {
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26)
                op2 = f(i - 2, s);
        }
        
        return dp[i]= op1 + op2;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n,-1);
        return f(n - 1, s);
    }
};