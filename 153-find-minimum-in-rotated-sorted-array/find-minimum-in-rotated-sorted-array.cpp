class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        int mid;
        if(n==1) return nums[0];
        if(nums[0]>nums[1]) return nums[1];
        if(nums[0]<nums[r]) return nums[0];
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        int idx=(r)%n;
        return nums[idx];
    }
};