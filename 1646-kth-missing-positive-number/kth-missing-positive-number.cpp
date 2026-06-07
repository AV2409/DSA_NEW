class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 1;
        int h = arr[n - 1] + k;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int present =
                upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int missing = mid - present;

            if (missing >= k)
                h = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};