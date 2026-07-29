class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int h=n-1;
        while(l<h){
            int mid=(l+h)/2;
            if(mid&1) mid--;
            
            if(nums[mid]==nums[mid+1]) l=mid+2;
            else h=mid;
        }
        return nums[l];
    }
};