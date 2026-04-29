class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int x=arr[i]-difference;
            if(dp.find(x)!=dp.end()){
                dp[arr[i]]=dp[x]+1;
            }
            else dp[arr[i]]=1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};