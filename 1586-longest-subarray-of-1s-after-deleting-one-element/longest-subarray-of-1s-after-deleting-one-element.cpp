class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int l = 0;
        int res = 0;
        int z = 0;
        while (l < n) {
            int r = l;
            while (r < n && nums[r] == 0) {
                r++;
                z++;
            }
            int st = r;
            if (st == n)
                break;
            while (r < n && nums[r] == 1)
                r++;

            if (nums[st] == 1) {
                ans.push_back({st, r - 1});
                res = max(res, r - st);
            }
            l = r;
        }

        if (z == 0)
            return n - 1;
        if (z == n)
            return 0;

        for (int i = 0; i < ans.size() - 1; i++) {
            int st1 = ans[i][0];
            int end1 = ans[i][1];
            int st2 = ans[i + 1][0];
            int end2 = ans[i + 1][1];

            if (st2 - end1 == 2)
                res = max(res, end1 - st1 + 1 + end2 - st2 + 1);
        }
        return res;
    }
};