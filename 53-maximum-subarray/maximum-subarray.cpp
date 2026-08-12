class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            bestEnding=max(nums[i],nums[i]+bestEnding);
            ans=max(ans,bestEnding);
        }
        return ans;
    }
};