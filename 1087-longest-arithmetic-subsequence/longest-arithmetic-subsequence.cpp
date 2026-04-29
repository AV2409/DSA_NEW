class Solution {
public:
    
    int solve(int idx,int diff,vector<int>& nums,vector<unordered_map<int,int>>&dp){
        if(idx<0) return 0;

        if(dp[idx].count(diff)) return dp[idx][diff];
        int ans=0;

        for(int i=idx-1;i>=0;i--){
            if(nums[idx]-nums[i]==diff){
                ans=max(ans,1+solve(i,diff,nums,dp));
            }
        }

        return dp[idx][diff]= ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i];
                ans=max(ans,2+solve(i,diff,nums,dp));
            }
        }
        return ans;
    }
};