class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];

        for(int i=1;i<n;i++){
            int tempMini=min({nums[i],mini*nums[i],maxi*nums[i]});
            int tempMaxi=max({nums[i],mini*nums[i],maxi*nums[i]});
            mini=tempMini;
            maxi=tempMaxi;
            ans=max(ans,maxi);
            
        }
        return ans;
    }
};