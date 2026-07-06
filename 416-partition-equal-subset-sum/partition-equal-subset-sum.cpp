class Solution {
public:
    vector<vector<int>>dp;
    bool f(int i, int sum,vector<int>& arr){
        if(i<0) return sum==0;
        if(i==0) return sum==arr[0];
        if(sum==0) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool np=f(i-1,sum,arr);
        bool p=false;

        if(arr[i]<=sum) p=f(i-1,sum-arr[i],arr);
        return dp[i][sum]= np||p;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        dp.assign(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        sum /= 2;
        return isSubsetSum(nums, sum);
    }
};