class Solution {
public:
    bool isPossible(int r,int c,char dig,vector<vector<char>>& board){
        int stR=(r/3)*3;
        int stC=(c/3)*3;

        for(int i=0;i<9;i++){
            if(i==c) continue;
            if(board[r][i]==dig) return false;
        }

        for(int i=0;i<9;i++){
            if(i==r) continue;
            if(board[i][c]==dig) return false;
        }

        for(int i=stR;i<stR+3;i++){
            for(int j=stC;j<stC+3;j++){
                if(i==r && j==c) continue;
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isPossible(i,j,ch,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};