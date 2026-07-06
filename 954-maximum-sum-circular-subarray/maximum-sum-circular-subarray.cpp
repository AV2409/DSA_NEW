class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];

        int currMaxi = nums[0];
        int currMini = nums[0];

        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            int combineMaxi = nums[i] + currMaxi;
            int combineMini = nums[i] + currMini;

            currMaxi = max(nums[i], combineMaxi);
            currMini = min(nums[i], combineMini);

            maxi = max(maxi, currMaxi);
            mini = min(mini, currMini);
        }
        if (maxi < 0)
            return maxi;

        int ans = max(maxi, sum - mini);
        return ans;
    }
};