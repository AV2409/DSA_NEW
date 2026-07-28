class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding=nums[0];
        int maxi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            //mix with prev
            int op1=bestEnding+nums[i];
            //start your own
            int op2=nums[i];

            bestEnding=max(op1,op2);
            maxi=max(maxi,bestEnding);
        }
        return maxi;

    }
};