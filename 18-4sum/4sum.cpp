class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int k = 0; k < n; k++) {
            for (int i = k + 1; i < n; i++) {
                int l = i + 1;
                int r = n - 1;
                while (l < r) {

                    long long sum = 1LL*nums[k] + nums[i] + nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back({nums[k], nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r + 1] == nums[r])
                            r--;
                    } else if (sum > target)
                        r--;
                    else if (sum < target)
                        l++;
                }
                while (i < n - 1 && nums[i] == nums[i + 1])
                i++;
            }
            while (k < n - 1 && nums[k] == nums[k + 1])
                k++;
        }
        return ans;
    }
};
