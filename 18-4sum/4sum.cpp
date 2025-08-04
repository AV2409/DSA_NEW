class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        for (int k = 0; k < n; k++) {
            for (int i = k+1; i < n; i++) {
                int l = i + 1;
                int r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[k] + (long long)nums[i] + (long long)nums[l] + (long long)nums[r];

                    if (sum == target) {
                        vector<int> temp = {nums[k],nums[i], nums[l], nums[r]};
                        st.insert(temp);
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};