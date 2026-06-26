class Solution {
public:

    bool isPossible(vector<vector<char>>& board,int i,int j,char ch){
        int sr=(i/3)*3;
        int sc=(j/3)*3;

        for(int r=sr;r<sr+3;r++){
            for(int c=sc;c<sc+3;c++){
                if(board[r][c]==ch) return false;
            }
        }

        for(int k=0;k<9;k++){
            if(board[i][k]==ch) return false;
            if(board[k][j]==ch) return false;
        }
        return true;

    }
    bool solve(vector<vector<char>>& board,int i,int j){
        if(j==9){
            i++;
            j=0;
        }
        if(i==9) return true;

        if(board[i][j]!='.') return solve(board,i,j+1);

        for(char ch='1';ch<='9';ch++){
            if(isPossible(board,i,j,ch)){
                board[i][j]=ch;
                if(solve(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        
    }
};