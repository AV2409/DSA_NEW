class Solution {
public:
    vector<int>cols;
    int N;
    vector<vector<string>>ans;

    bool isPossible(int row,int col){
        int ss=cols.size();
        for(int r=0;r<ss;r++){
            int c=cols[r];
            if(c==col) return false;

            if(abs(row-r)==abs(col-c)) return false;
        }
        return true;
    }
    void storeAns(){
        vector<string>str(N,string(N,'.'));
        for(int r=0;r<N;r++){
            int c=cols[r];
            str[r][c]='Q';
        }
        ans.push_back(str);
    }
    void solve(int row){
        if(row==N){
            storeAns();
            return;
        }

        for(int col=0;col<N;col++){
            if(isPossible(row,col)){
                cols.push_back(col);
                solve(row+1);
                cols.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        solve(0);
        return ans;
    }
};