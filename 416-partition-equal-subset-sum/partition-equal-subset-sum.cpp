class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                int np = dp[i - 1][j];
                int p = 0;
                if (arr[i - 1] <= j) {
                    p = dp[i - 1][j - arr[i - 1]];
                }
                dp[i][j] = (np || p);
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) {
            return 0;
        }
        int target = sum / 2;
        return isSubsetSum(nums, target);
    }
};