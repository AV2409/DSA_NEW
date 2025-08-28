class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[r];
    }
};