class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col){
        char ch=board[row][col];
        board[row][col]='.';

        for(int i=0;i<9;i++){
            if(board[row][i]==ch ||board[i][col]==ch) return false;
        }

        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==ch) return false;
            }
        }
        board[row][col]=ch;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(check(board,i,j)==false) return false;
                }
            }
        }
        return true;
    }
};