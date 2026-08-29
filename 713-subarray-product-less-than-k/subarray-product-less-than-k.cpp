class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int prod=1;
        int n=nums.size();
        int ans=0;

        for(int r=0;r<n;r++){
            prod=prod*nums[r];
            while(l<n && prod>=k){
                prod=prod/nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};