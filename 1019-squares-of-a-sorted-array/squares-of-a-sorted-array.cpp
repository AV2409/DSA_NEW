class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        int idx=0;
        int mini=INT_MAX;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < mini){
                mini=abs(nums[i]);
                idx=i;
            }
        }
        int l=idx-1;
        int r=idx;

        while (l >= 0 && r < n) {
            if (abs(nums[l]) <= nums[r]) {
                ans.push_back(nums[l] * nums[l]);
                l--;
            } else {
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }

        while (l >= 0) {
            ans.push_back(nums[l] * nums[l]);
            l--;
        }

        while (r < n) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }
        return ans;
    }
};