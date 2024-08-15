class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int rows = arr.size();
        int cols = arr[0].size();
        int i = 0;
        int j = cols-1;
        while (i < rows && j >= 0) {
            if (arr[i][j] == target) {
                return true;
            }

            else if (arr[i][j] < target)
                i++;

            else
                j--;
        }
        return false;
    }
};