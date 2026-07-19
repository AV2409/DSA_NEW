class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int lis = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (1 + dp[j] > dp[i]) {
                        cnt[i] = cnt[j];
                        dp[i] = 1 + dp[j];
                    } else if (1 + dp[j] == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > lis) {
                lis = dp[i];
                ans = cnt[i];
            } else if (dp[i] == lis) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};