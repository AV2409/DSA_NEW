class Solution {
public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> n1 = nums;
        reverse(nums.begin(), nums.end());
        vector<int> n2 = nums;

        vector<int> ans1 = lengthOfLIS(n1);
        vector<int> ans2 = lengthOfLIS(n2);
        reverse(ans2.begin(), ans2.end());
        // for(int x:ans1) cout<<x<<" ";
        // cout<<endl;
        // for(int x:ans2) cout<<x<<" ";
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (ans1[i] > 1 && ans2[i] > 1) {
                maxi = max(maxi, ans1[i] + ans2[i] - 1);
            }
        }
        // return size1+size2-ans1-ans2;
        return n - maxi;
    }
};