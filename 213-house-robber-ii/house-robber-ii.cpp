class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1); // dp[i] represents max sum for first i elements
        dp[0] = 0;             // Base case: no elements
        dp[1] = arr[0];        // Base case: only first element

        for (int i = 2; i <= n; i++) {
            int np = dp[i - 1];             // Not pick current element
            int p = arr[i - 1] + dp[i - 2]; // Pick current element
            dp[i] = max(p, np);             // Store max in dp[i]
        }

        return dp[n]; // Final answer
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0]; // Important base case
        vector<int> temp(nums.begin() + 1, nums.end());
        int x1 = findMaxSum(temp);

        vector<int> temp1(nums.begin(), nums.end() - 1);
        int x2 = findMaxSum(temp1);

        return max(x1, x2);
    }
};