class Solution {
private:
    bool binary_search(vector<int> arr, int target) {
        int n = arr.size();
        int st = 0;
        int end = n - 1;
        int mid = st + (end - st) / 2;
        while (st <= end) {
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] > target)
                end = mid - 1;

            else
                st = mid + 1;
            mid = st + (end - st) / 2;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int rows = arr.size();
        int cols = arr[0].size();
        int s = 0;
        int e = cols - 1;
        bool found = false;
        int i;
        for (i = 0; i < rows; i++) {
            if (target >= arr[i][s] && target <= arr[i][e]) {
                found = binary_search(arr[i], target);
            }
            if (found)
                return found;
        }

        return found;
    }
};