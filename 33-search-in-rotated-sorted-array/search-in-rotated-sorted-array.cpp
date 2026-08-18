class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            //left sorted
            if(nums[l]<=nums[mid]){
                //left sorted part
                if(target>=nums[l] && target<=nums[mid]) h=mid-1;

                //right unsorted part
                else l=mid+1;
            }
            //right sorted
            else{
                //right sorted part
                if(target>=nums[mid] && target<=nums[h]) l=mid+1;

                //left unsorted part
                else h=mid-1;
            }
        }
        return -1;
    }
};