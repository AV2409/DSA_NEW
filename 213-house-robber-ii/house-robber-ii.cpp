class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++) {
            int o1 = dp[i - 1];
            int o2 = nums[i] + dp[i - 2];

            dp[i] = max(o1, o2);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> temp(nums.begin(), nums.end() - 1);
        vector<int> temp1(nums.begin() + 1, nums.end());

        int x1 = helper(temp);
        int x2 = helper(temp1);

        return max(x1, x2);
    }
};