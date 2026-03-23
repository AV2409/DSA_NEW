class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int currMax=nums[0];
        int currMin=nums[0];

        for(int i=1;i<n;i++){
            int op1=nums[i];
            int op2=nums[i]*currMax;
            int op3=nums[i]*currMin;

            currMax=max({op1,op2,op3});
            currMin=min({op1,op2,op3});

            ans=max(ans,currMax);
        }
        return ans;
    }
};