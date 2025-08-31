class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n - 2;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]) return mid;
            else if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else if (nums[mid] < nums[mid - 1]) {
                r = mid - 1;
            }
        }
        return 0;
    }
};