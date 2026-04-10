class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool> prev(sum + 1);
        prev[0] = true; // dp[i-1]

        for (int i = 1; i <= n; i++) {
            vector<bool> curr(sum + 1); // dp[i]
            curr[0] = true;
            for (int x = 1; x <= sum; x++) {
                // not pick
                bool op1 = prev[x];
                bool op2 = false;

                if (x - arr[i - 1] >= 0)
                    op2 = prev[x - arr[i - 1]];

                curr[x] = op1 || op2;
            }

            prev = curr;
        }

        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        sum /= 2;
        return isSubsetSum(nums, sum);
    }
};