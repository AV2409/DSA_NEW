class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
                continue;
            }

            // left half sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // right half sorted
            else {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};