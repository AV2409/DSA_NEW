class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int p2 = 0;      // Base case: no elements
        int p1 = arr[0]; // Base case: only first element
        int curr = 0;

        for (int i = 2; i <= n; i++) {
            int np = p1;             // Not pick current element
            int p = arr[i - 1] + p2; // Pick current element
            curr = max(p, np);       // Store max in dp[i]
            p2 = p1;
            p1 = curr;
        }

        return p1; // Final answer
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
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