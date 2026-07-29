class Solution {
public:
    bool isPossible(int row,int col,char ch,vector<vector<char>>& board){
        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int r=sr;r<sr+3;r++){
            for(int c=sc;c<sc+3;c++){
                if(r==row&&c==col) continue;
                if(board[r][c]==ch) return false;
            }
        }

        for(int i=0;i<9;i++){
            if(i==col) continue;
            if(board[row][i]==ch) return false;
        }

        for(int i=0;i<9;i++){
            if(i==row) continue;
            if(board[i][col]==ch) return false;
        }

        return true;
    }
    bool solve(int row,int col,vector<vector<char>>& board){
        if(col==9){
            row++;
            col=0;
        }
        if(row==9) return true;
        if(board[row][col]!='.') return solve(row,col+1,board);

        for(char ch='1';ch<='9';ch++){
            if(isPossible(row,col,ch,board)){
                board[row][col]=ch;
                if(solve(row,col+1,board)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};