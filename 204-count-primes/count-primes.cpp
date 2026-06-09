class Solution {
public:
    vector<int> sieve;

    void solve(int n) {
        sieve.assign(n + 1, 1);
        sieve[0] = sieve[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i+i; j <= n; j += i) {
                    sieve[j] = 0;
                }
            }
        }
    }
    int countPrimes(int n) {
        if (n <= 2) return 0;
        solve(n - 1);
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            cnt += sieve[i];
        }
        return cnt;
    }
};