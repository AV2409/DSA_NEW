class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n = n / 10;
        }
        return ans;
    }
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    int sumOfPrimesInRange(int n) {
        
        int rev = reverse(n);

        int st = min(n, rev);
        int end = max(n, rev);
        vector<bool>isPrime=sieve(end);
        int ans = 0;
        for (int i = st; i <= end; i++) {
            if (isPrime[i]) {
                cout<<i<<" ";
                ans += i;
            }
        }
        return ans;
    }
};