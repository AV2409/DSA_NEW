class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0; // There are no primes less than 2

        int count = 0;
        int i = 2;
        int prime[n];
        fill_n(prime, n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i; j * i < n; j++) {
                    prime[j * i] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (prime[i] == 1)
                count++;
        }
        return count;
    }
};