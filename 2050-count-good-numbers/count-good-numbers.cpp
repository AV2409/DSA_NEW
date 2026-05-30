class Solution {
public:
    long long helper(long long x, long long n) {
        if (n == 0)
            return 1;

        long long tt = helper(x, n / 2)%MOD;
        long long res = (tt * tt) % MOD;
        if (n % 2)
            res = (res * (x % MOD)) % MOD;
        return res;
    }
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long pow = n / 2;
        long long x = helper(20, pow) % MOD;
        if (n % 2)
            return (5 * x) % MOD;
        return x % MOD;
    }
};