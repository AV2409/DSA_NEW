class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        if (s[0] == '1')
            ans += nums[0];
        int idx = 1;
        while (idx < n) {
            int l = idx;
            int r = idx;
            if (s[l] == '1') {
                long long sum = 0;
                int mini = nums[l];
                while (r < n && s[r] == '1') {
                    mini = min(mini, nums[r]);
                    sum += nums[r];
                    r++;
                }

                if (s[l - 1] == '0') {
                    sum += nums[l - 1];
                    mini = min(nums[l - 1], mini);
                    sum -= mini;
                    ans += sum;
                } else {
                    ans += sum;
                }
                idx = r + 1;
            }
            else idx++;
            
        }
        return ans;
    }
};