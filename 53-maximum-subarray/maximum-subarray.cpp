class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding=nums[0];
        int n=nums.size();
        int ans=nums[0];

        for(int i=1;i<n;i++){
            int op1=nums[i];
            int op2=bestEnding+nums[i];
            bestEnding=max(op1,op2);
            ans=max(ans,bestEnding);
        }
        return ans;

    }
};