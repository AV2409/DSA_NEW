class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int bestMin=nums[0];
        int bestMax=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int tempMax=max({nums[i],nums[i]*bestMin,nums[i]*bestMax});
            int tempMin=min({nums[i],nums[i]*bestMin,nums[i]*bestMax});

            bestMin=tempMin;
            bestMax=tempMax;
            ans=max(ans,bestMax);
        }
        return ans;
    }
};