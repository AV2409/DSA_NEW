class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;

        while(l<h){
            int mid=(l+h)/2;
            
            if(nums[l]<nums[h]) return nums[l];
            if(nums[l]==nums[mid] && nums[mid]==nums[h]){
                l++;
                h--;
                continue;
            }
            if(nums[l]<=nums[mid]){
                //left sorted
                l=mid+1;
            }

            else{
                //right sorted
                h=mid;
            }
        }
        return nums[l];
    }
};
