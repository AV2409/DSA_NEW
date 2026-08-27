class Solution {
public:
    vector<int> sieve;
    void findSieve() {
        sieve[0] = 0;
        sieve[1] = 0;
        int n = sieve.size();
        for (int i = 2; i * i < n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = 0;
                }
            }
        }
    }
    vector<int> findFac(int n) {
        vector<int> ans;

        for (int i = 2; i * i <= n; i++) {
            if (sieve[i] && n % i == 0) {
                ans.push_back(i);

                while (n % i == 0)
                    n /= i;
            }
        }

        if (n > 1)
            ans.push_back(n);

        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());

        sieve.assign(maxi + 1, 1);
        findSieve();
        int n = nums.size();
        vector<vector<int>> primeFactors;

        for (int i = 0; i < n; i++) {
            primeFactors.push_back(findFac(nums[i]));
        }

        // for(auto v:primeFactors){
        //     for(int x:v){
        //         cout<<x<<"-";
        //     }
        //     cout<<endl;
        // }

        int unq = 0;
        unordered_map<int, int> mp;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            // include nums[r];
            for (int fac : primeFactors[r]) {
                if (mp[fac] == 0)
                    unq++;
                mp[fac]++;
            }

            while (unq > k) {
                for (int fac : primeFactors[l]) {
                    mp[fac]--;
                    if (mp[fac] == 0)
                        unq--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};