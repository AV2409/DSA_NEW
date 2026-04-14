class Solution {
public:
    int f(int eggs,int floor,vector<vector<int>>&dp){
        if(eggs==1) return floor;
        if(floor==0||floor==1) return floor;
        if(dp[eggs][floor]!=-1) return dp[eggs][floor];
        int mini=1e9;
        int low = 1, high = floor;
        while(low <= high){
            int mid = (low + high) / 2;

            int op1 = f(eggs - 1, mid - 1, dp);
            int op2 = f(eggs, floor - mid, dp);

            int temp = 1 + max(op1, op2);
            mini = min(mini, temp);

            if(op1 > op2)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return dp[eggs][floor]= mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
    }
};