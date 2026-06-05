class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestP=1;
        int bestN=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int op1=nums[i];
            int op2=nums[i]*bestP;
            int op3=nums[i]*bestN;

            bestP=max({op1,op2,op3});
            bestN=min({op1,op2,op3});
            ans=max(ans,bestP);
        }
        return ans;
    }
};