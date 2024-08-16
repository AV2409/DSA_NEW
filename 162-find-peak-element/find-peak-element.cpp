class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        if(nums.size()==1) return 0;
        if (nums[0] > nums[1]) return 0;
        while(s<e){
            
            if(nums[mid]<nums[mid+1]) s=mid+1;

            else if(nums[mid]<nums[mid-1]) e=mid;

            else return mid;

            mid=s+(e-s)/2;

        }
        return e;
    }
};