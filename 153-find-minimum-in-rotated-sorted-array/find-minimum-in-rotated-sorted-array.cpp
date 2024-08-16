class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int mid=st+(end-st)/2;
        while(st<end)
        {
            if(nums[st]<nums[end]) return nums[st];

            else if(nums[mid]>=nums[st]) st=mid+1;

            else end=mid;

            mid=st+(end-st)/2;

        }

        return nums[end];
    }
};