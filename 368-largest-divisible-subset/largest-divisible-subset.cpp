class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
        vector<int>dp(n,1);
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int st=-1;
        int lis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(1+dp[j]>dp[i]){
                        par[i]=j;
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i]>lis) st=i;
            lis=max(lis,dp[i]);
        }
        vector<int>ans(lis);
        int idx=lis-1;
        while(par[st]!=st){
            ans[idx]=nums[st];
            st=par[st];
            idx--;
        }
        ans[idx]=nums[st];
        return ans; 
    }
};