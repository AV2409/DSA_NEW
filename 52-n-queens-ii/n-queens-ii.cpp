class Solution {
public:
    vector<int>cols;
    int N;
    // vector<vector<string>>ans;
    
    int ans=0;
    bool isPossible(int row,int col){
        int x=cols.size();
        for(int r=0;r<x;r++){
            int c=cols[r];
            if(c==col||abs(row-r)==abs(col-c)) return false;
        }
        return true;
    }
    void solve(int row){
        if(row==N){
            ans++;
            return;
        }

        for(int col=0;col<N;col++){
            if(isPossible(row,col)) {
                cols.push_back(col);
                solve(row+1);
                cols.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        N=n;
        solve(0);
        return ans;
    }
};