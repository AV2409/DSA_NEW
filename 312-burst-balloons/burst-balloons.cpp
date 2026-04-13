class Solution {
public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>> &dp){
        if(abs(i-j)<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=-1;
        for(int k=i+1;k<j;k++){
            int cc=arr[i]*arr[k]*arr[j]+(f(i,k,arr,dp)+f(k,j,arr,dp));
            temp=max(temp,cc);
        }
        return dp[i][j]= temp;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);
        int maxi=0;
        for(int x:nums){
            arr.push_back(x);
            maxi=max(x,maxi);
        }

        arr.push_back(1);
        int m=arr.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(0,m-1,arr,dp);

    }
};