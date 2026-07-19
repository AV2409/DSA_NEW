class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int s=1;s<=sum;s++){
                bool pick=false;
                bool np=dp[i-1][s];
                if(s>=arr[i-1]) pick=dp[i-1][s-arr[i-1]];
                dp[i][s]= pick||np;
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        return isSubsetSum(nums,sum/2);
    }
};