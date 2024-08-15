class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int count = 0;
        int rows = arr.size();
        int cols = arr[0].size();
        int startRow = 0;
        int startCol = 0;
        int endRow = rows - 1;
        int endCol = cols - 1;

        int total = rows * cols;
        while (count < total) {
            // printing starting row
            for (int i = startCol; i <= endCol && count < total; i++) {
                ans.push_back(arr[startRow][i]);
                count++;
            }
            startRow++;

            // printing ending col
            for (int i = startRow; i <= endRow && count < total; i++) {
                ans.push_back(arr[i][endCol]);
                count++;
            }
            endCol--;

            // printing ending row
            for (int i = endCol; i >= startCol && count < total; i--) {
                ans.push_back(arr[endRow][i]);
                count++;
            }
            endRow--;

            // printing starting col
            for (int i = endRow; i >= startRow && count < total; i--) {
                ans.push_back(arr[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};