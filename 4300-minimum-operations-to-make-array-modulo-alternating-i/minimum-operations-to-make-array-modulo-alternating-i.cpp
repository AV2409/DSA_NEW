class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % k;
        }

        vector<vector<int>> v(n, vector<int>(k));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int d = abs(j - nums[i]);
                v[i][j] = min(d, k - d);
            }
        }

        vector<int> odd(k, 0);
        vector<int> even(k, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (i % 2 == 0)
                    even[j] += v[i][j];
                else
                    odd[j] += v[i][j];
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j)
                    continue;
                int temp = even[i] + odd[j];
                ans = min(ans, temp);
            }
        }
        return ans;
    }
};