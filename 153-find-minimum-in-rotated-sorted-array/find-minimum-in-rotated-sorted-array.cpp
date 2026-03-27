class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        int ans=-1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[n - 1])
                l = mid + 1;
            else {
                ans=mid;
                r = mid-1;
            }
        }
        return nums[ans];
    }
};