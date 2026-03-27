class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        int ans = -1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else {
                ans = mid;
                r = mid - 1;
            }
        }
        if (ans == -1)
            return 0;
        return ans;
    }
    int bs(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2; // avoids overflow

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1; // not found
    }
    int search(vector<int>& nums, int target) {
        int x = findMin(nums);
        vector<int> arr1(nums.begin(), nums.begin() + x);
        vector<int> arr2(nums.begin() + x, nums.end());

        int a1 = bs(arr1, target);
        int a2 = bs(arr2, target);

        if (a1 != -1)
            return a1;
        if (a2 != -1)
            return a2+x;
        return -1;
    }
};