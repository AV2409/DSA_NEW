class Solution {
public:
    
    vector<int> dp;
    int f(int i, vector<int>& nums) {
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = nums[i] + f(i - 2, nums);
        int notpick = f(i - 1, nums);

        return dp[i] = max(pick, notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> hash(maxi + 1, 0);
        dp.assign(maxi+1,-1);
        for (auto it : mp) {
            hash[it.first] = it.first * it.second;
        }
        return f(maxi, hash);
    }
};