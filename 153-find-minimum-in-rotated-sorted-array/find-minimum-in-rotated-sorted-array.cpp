class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        int ans=5001;
        while (l <= r) {
            int mid = (l + r) / 2;

            if(nums[l]<=nums[mid]) {
                ans=min(nums[l],ans);
                l=mid+1;
            }
            else {
                ans=min(nums[mid],ans);
                r = mid-1;
            }
           
        }
        return ans;;
    }
};