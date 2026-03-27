class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int n = arr.size();
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                cnt++;
                sum = arr[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        if (k > n)
            return -1;
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isPossible(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return ans;
    }
};