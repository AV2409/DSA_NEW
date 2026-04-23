class Solution {
public:
    vector<int> cols;
    vector<vector<string>> ans;

    bool isPossible(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (col == cols[i])
                return false;
            if (abs(row - i) == abs(col - cols[i]))
                return false;
        }
        return true;
    }
    void helper(int row, int n) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][cols[i]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isPossible(row, col)) {
                cols.push_back(col);
                helper(row + 1, n);
                cols.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        helper(0,n);
        return ans;
    }
};