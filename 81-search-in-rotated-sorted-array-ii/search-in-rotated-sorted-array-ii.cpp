class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            
            if(nums[mid]==target) return true;
            if(nums[l]==nums[mid]) l++;
            // Left half is sorted
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }
};