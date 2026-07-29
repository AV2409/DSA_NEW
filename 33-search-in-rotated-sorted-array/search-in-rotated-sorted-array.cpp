class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            //left sorted
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && nums[mid]>=target){
                    r=mid-1;
                }
                else l=mid+1;
            }

            //right sorted
            else{
                if(target<=nums[r] && nums[mid]<=target){
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        return -1;
    }
};