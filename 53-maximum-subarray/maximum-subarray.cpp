class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            bestEnding=max(nums[i],nums[i]+bestEnding);
            ans=max(ans,bestEnding);
        }
        return ans;
    }
};