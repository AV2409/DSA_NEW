class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> num(n + 1, 0);   // prefix number (non-zero digits only)
        vector<int> sum(n + 1, 0);         // prefix sum of non-zero digits
        vector<int> cnt(n + 1, 0);         // prefix count of non-zero digits
        vector<long long> pow10(n + 1, 1);

        // Precompute powers of 10
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix preprocessing
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sum[i] = sum[i - 1];
            cnt[i] = cnt[i - 1];
            num[i] = num[i - 1];

            if (d != 0) {
                sum[i] += d;
                cnt[i]++;
                num[i] = (num[i - 1] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long digitSum = sum[r + 1] - sum[l];

            // Number of non-zero digits in the range
            int k = cnt[r + 1] - cnt[l];

            // Recover x
            long long x = (num[r + 1] -
                           (num[l] * pow10[k]) % MOD +
                           MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};