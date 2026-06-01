class Solution {
public:
    vector<int> cols;
    vector<vector<int>> ans;
    bool canPlace(int idx) {
        int ss = cols.size();
        for (int i = 0; i < ss; i++) {
            if (cols[i] == idx)
                return false;
            if (abs(idx - cols[i]) == abs(ss - i))
                return false;
        }
        return true;
    }
    void f(int i, int n) {
        if (i == n) {
            ans.push_back(cols);
            return;
        }

        for (int idx = 0; idx < n; idx++) {
            if (canPlace(idx)) {
                cols.push_back(idx);
                f(i + 1, n);
                cols.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        f(0, n);
        vector<vector<string>> res;

        for (auto& col : ans) {
            vector<string> board(n, string(n, '.'));
            for (int row = 0; row < n; row++) {
                board[row][col[row]] = 'Q';
            }
            res.push_back(board);
        }

        return res;
    }
};