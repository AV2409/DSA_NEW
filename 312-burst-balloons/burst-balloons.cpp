class Solution {
public:
    vector<vector<int>>dp;
    int f(int st,int end,vector<int>&arr){
        if(st>end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans=INT_MIN;
        for(int i=st;i<=end;i++){
            int temp=arr[st-1]*arr[i]*arr[end+1]+f(st,i-1,arr)+f(i+1,end,arr);
            ans=max(ans,temp);
        }
        return dp[st][end]= ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);
        for(int x:nums) arr.push_back(x);
        arr.push_back(1);

        int st=1;
        int end=nums.size();

        dp.assign(end+1,vector<int>(end+1,-1));

        return f(st,end,arr);
    }
};