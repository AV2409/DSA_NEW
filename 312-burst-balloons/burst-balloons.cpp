class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            int temp=f(i,k-1,nums)+f(k+1,j,nums)+nums[i-1]*nums[k]*nums[j+1];
            ans=max(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>x={1};
        for(int i:nums){
            x.push_back(i);
        }
        x.push_back(1);
        int i=1;
        int n = nums.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(i,n,x);
    }
};