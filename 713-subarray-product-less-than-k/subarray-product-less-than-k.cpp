class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int pre = 1;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            pre = pre * nums[r];
            while (l<=r+1 && l<n && pre >= k) {
                pre = pre / nums[l];
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};