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

    bool isPrime(int n) {
        if(n==1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);

        int st = min(n, rev);
        int end = max(n, rev);
        int ans = 0;
        for (int i = st; i <= end; i++) {
            if (isPrime(i)) {
                cout<<i<<" ";
                ans += i;
            }
        }
        return ans;
    }
};