class Solution {
public:
    vector<int> primes;
    vector<int> seive;

    void solve() {
        int n = seive.size();
        for (long long i = 2; i < n; i++) {
            if (seive[i] == 0) {
                continue;
            }
            primes.push_back(i);

            for (long long j = i * i; j < n; j += i) {
                seive[j] = 0;
            }
        }
    }

    int findUpper(int num) {
        return *lower_bound(primes.begin(), primes.end(), num);
    }

    int minOperations(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        seive.resize(2 * maxi + 1, 1);
        seive[1] = 0;
        seive[0] = 0;
        solve();
        int n = nums.size();
        long long opr = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 && seive[nums[i]]) {
                if (nums[i] == 2)
                    opr++;
                opr++;
            } else if (i % 2 == 0 && !seive[nums[i]]) {
                int n1 = findUpper(nums[i]);
                opr += n1 - nums[i];
            }
        }
        return opr;
    }
};