class Solution {
public:
    vector<vector<int>>dp;
    int solve(int idx,int diff,vector<int>& nums){
        if(idx<0) return 0;
        int d=diff+500;
        if(dp[idx][d]!=-1) return dp[idx][d];
        int ans=0;

        for(int i=idx-1;i>=0;i--){
            if(nums[idx]-nums[i]==diff){
                ans=max(ans,1+solve(i,diff,nums));
            }
        }

        return dp[idx][d]= ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        dp.assign(n,vector<int>(1005,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i];
                ans=max(ans,2+solve(i,diff,nums));
            }
        }
        return ans;
    }
};