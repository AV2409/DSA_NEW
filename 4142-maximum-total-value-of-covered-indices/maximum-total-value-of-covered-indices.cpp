class Solution {
public:
    vector<vector<long long>> dp;

    long long f(int i, int occupied, vector<int>& nums, string& s) {
        if (i < 0) return 0;
        if (dp[i][occupied] != -1)
            return dp[i][occupied];

        long long ans;
        if (occupied) {
            ans = nums[i];

            if (s[i] == '1')
                ans += f(i - 1, 1, nums, s);
            else
                ans += f(i - 1, 0, nums, s);
        }
        else {
            if (s[i] == '0') {
                ans = f(i - 1, 0, nums, s);
            }
            else {
                long long stay = nums[i] + f(i - 1, 0, nums, s);
                long long move = f(i - 1, 1, nums, s);
                ans = max(stay, move);
            }
        }

        return dp[i][occupied] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {

        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        int idx = n - 1;
        return f(idx, 0, nums, s);
    }
};