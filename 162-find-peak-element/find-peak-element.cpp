class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int prev=INT_MIN;
            int next=INT_MIN;
            if(mid-1>=0) prev=nums[mid-1];
            if(mid+1<n) next=nums[mid+1];
            if(nums[mid]>prev && nums[mid]>next) return mid;
            else if(nums[mid]<next) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};