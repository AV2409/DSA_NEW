class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 1e9;
        int sum = 0;

        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                int len = r - l + 1;
                ans = min(len, ans);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        if (ans == 1e9)
            return 0;
        return ans;
    }
};