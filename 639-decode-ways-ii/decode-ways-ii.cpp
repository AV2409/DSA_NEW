class Solution {
public:
    const int MOD=1e9+7;
    vector<int> dp;
    int f(int i, string& s) {
        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];
        long long op1 = 0, op2 = 0;

        if (s[i] == '*') {
            op1 = 9LL * f(i - 1, s);
            if (i - 1 >= 0) {
                if (s[i - 1] == '1')
                    op2 = 9LL * f(i - 2, s);
                if (s[i - 1] == '2')
                    op2 = 6LL * f(i - 2, s);
                if (s[i - 1] == '*')
                    op2 = 15LL * f(i - 2, s);
            }
        } else {
            int nn = s[i] - '0';
            if (nn >= 1 && nn <= 9) {
                op1 = f(i - 1, s);
            }

            if (i - 1 >= 0) {
                if (s[i - 1] == '*') {
                    if (s[i] - '0' <= 6)
                        op2 = 2LL * f(i - 2, s);
                    else
                        op2 = f(i - 2, s);
                } else {
                    int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
                    if (num >= 10 && num <= 26)
                        op2 = f(i - 2, s);
                }
            }
        }

        return dp[i] = (op1%MOD + op2%MOD)%MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n, -1);
        return f(n - 1, s);
    }
};

// class Solution {
// public:
//     vector<int> dp;
//     int f(int i, string& s) {
//         if (i < 0)
//             return 1;

//         if (dp[i] != -1)
//             return dp[i];

//         if (s[i] == '*') {
//             int op1 = 0;
//             int op2 = 0;
//             for (char ch = '1'; ch <= '9'; ch++) {
//                 s[i] = ch;
//                 int nn = s[i] - '0';
//                 if (nn >= 1 && nn <= 9) {
//                     op1 += f(i - 1, s);
//                 }

//                 if (i - 1 >= 0) {
//                     int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
//                     if (num >= 10 && num <= 26)
//                         op2 += f(i - 2, s);
//                 }
//             }
//             return dp[i] = op1 + op2;
//         }
//         int op1 = 0;
//         int op2 = 0;

//         int nn = s[i] - '0';
//         if (nn >= 1 && nn <= 9) {
//             op1 = f(i - 1, s);
//         }

//         if (i - 1 >= 0) {
//             int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
//             if (num >= 10 && num <= 26)
//                 op2 = f(i - 2, s);
//         }

//         return dp[i] = op1 + op2;
//     }
//     int numDecodings(string s) {
//         int n = s.size();
//         dp.assign(n, -1);
//         return f(n - 1, s);
//     }
// };