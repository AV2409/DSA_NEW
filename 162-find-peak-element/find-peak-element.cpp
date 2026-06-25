class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int l=0;
        int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            int prev=INT_MIN;
            int next=INT_MIN;

            if(mid>0) prev=nums[mid-1];
            if(mid<n-1) next=nums[mid+1];
            if(nums[mid]>prev && nums[mid]>next){
                return mid;
            }
            else if(nums[mid]>=prev) l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};