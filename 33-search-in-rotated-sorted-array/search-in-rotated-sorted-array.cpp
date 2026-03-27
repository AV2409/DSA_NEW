class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int n=r+1;
        int mid;
        while(l <= r) {
            mid=(l+r)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > nums[n - 1]) {
                if (target > nums[mid]) {
                    l = mid + 1;
                } else {
                    if (target >= nums[0])
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }
            // 2nd part nums[mid]<=nums[n-1]
            else {
                if (target < nums[mid]) {
                    r = mid - 1;
                } else {
                    if (target > nums[n-1])
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }
        }
        return -1;
    }
};