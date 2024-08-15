class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int>(n));
        int startRow = 0;
        int startCol = 0;
        int endRow = n - 1;
        int endCol = n - 1;
        int count=1;

        int total = n * n;
        while (count <= total) {
            // printing starting row
            for (int i = startCol; i <= endCol && count <= total; i++) {
                ans[startRow][i] = count;
                
                count++;
            }
            startRow++;

            // printing ending col
            for (int i = startRow; i <= endRow && count <= total; i++) {
                ans[i][endCol] = count;
                count++;
            }
            endCol--;

            // printing ending row
            for (int i = endCol; i >= startCol && count <= total; i--) {
                ans[endRow][i] = count;
                
                count++;
            }
            endRow--;

            // printing starting col
            for (int i = endRow; i >= startRow && count <= total; i--) {
                ans[i][startCol] = count;
                count++;
            }
            startCol++;
        }
        return ans;
    }
};