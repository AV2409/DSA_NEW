class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int res = 0;
        int n = nums.size();
        while (r < n && l<n) {
            if (nums[r] == 0) {
                if (k > 0) {
                    k--;
                    r++;
                } else {
                    if (nums[l] == 0) {
                        k++;
                    }
                    l++;
                }
            }
            else
                r++;

            res = max(res, r - l);
        }
        return res;
    }
};