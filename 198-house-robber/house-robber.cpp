class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp;
        dp.assign(n,0);
        for(int i=0;i<n;i++){
            int pick=nums[i];
            int np=0;
            if(i-1>=0) np+=dp[i-1];
            if(i-2>=0) pick+=dp[i-2];
            dp[i]=max(pick,np);
        }
        return dp[n-1];
    }
};