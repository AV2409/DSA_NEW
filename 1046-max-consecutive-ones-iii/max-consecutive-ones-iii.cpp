class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int res = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0)
                k--;

            if(k < 0) {
                if (nums[l] == 0) {
                    k++;
                }
                l++;
            }

            if(k>=0) res = max(res, r - l+1);
            r++;
        }
        return res;
    }
};