class Solution {
public:
    int perfectSum_tab(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int np = dp[i - 1][j];
                int p = 0;
                if (arr[i - 1] <= j) {
                    p = dp[i - 1][j - arr[i - 1]];
                }
                dp[i][j] = (np + p);
            }
        }
        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if ((sum - target) < 0 || (sum - target) % 2 != 0) {
            return 0;
        }

        int d = (sum - target) / 2;
        return perfectSum_tab(nums, d);
    }
};