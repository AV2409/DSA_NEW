class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        int mid;
        int idx = -1;
        pair<int, int> bestDiff = {INT_MAX, INT_MAX};
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int diff = abs(arr[mid] - x);

            if (diff < bestDiff.first ||
                (diff == bestDiff.first && arr[mid] < bestDiff.second)) {
                bestDiff = {diff, arr[mid]};
                idx = mid;
            }

            if (arr[mid] < x)
                lo = mid + 1;

            else
                hi = mid - 1;
        }

        int i = idx;
        int j = idx + 1;
        vector<int> ans;
        while (k && i >= 0 && j < n) {
            if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                ans.push_back(arr[i]);
                i--;
            }

            else {
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }

        while (k && i >= 0) {
            ans.push_back(arr[i--]);
            k--;
        }

        while (k && j < n) {
            ans.push_back(arr[j++]);
            k--;
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};