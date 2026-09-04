class Solution {
private:
    bool isPossible(int row, int col) {
        int ss = cols.size();
        for (int r = 0; r < ss; r++) {
            int c = cols[r];
            if (c == col || abs(r - row) == abs(c - col))
                return false;
        }
        return true;
    }

    void updateAns(){
        vector<string>temp(N,string(N,'.'));
        int ss=cols.size();
        for(int r=0;r<ss;r++){
            int c=cols[r];
            temp[r][c]='Q';
        }
        ans.push_back(temp);
    }

public:
    vector<vector<string>> ans;
    vector<int> cols;
    int N;

    void solve(int row) {
        if (row == N) {
            updateAns();
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isPossible(row, col)) {
                cols.push_back(col);
                solve(row + 1);
                cols.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        solve(0);
        return ans;
    }
};