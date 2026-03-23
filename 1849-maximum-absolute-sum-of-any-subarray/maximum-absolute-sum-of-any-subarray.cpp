class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int ans_min=nums[0];
        int ans_max=nums[0];

        int currMax=nums[0];
        int currMin=nums[0];

        for(int i=1;i<n;i++){
            int op1=nums[i];

            int op21=nums[i]+currMax;
            int op22=nums[i]+currMin;

            currMax=max(op1,op21);
            currMin=min(op1,op22);

            ans_max=max(ans_max,currMax);
            ans_min=min(ans_min,currMin);
        }

        return max(abs(ans_max),abs(ans_min));
    }
};