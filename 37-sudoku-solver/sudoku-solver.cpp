class Solution {
public:

    bool isPossible(vector<vector<char>>& board,int i,int j){
        int sr=(i/3)*3;
        int sc=(j/3)*3;

        for(int r=sr;r<sr+3;r++){
            for(int c=sc;c<sc+3;c++){
                if(r==i && c==j) continue;
                if(board[r][c]==board[i][j]) return false;
            }
        }

        for(int x=0;x<9;x++){
            if(x==i) continue;
            if(board[x][j]==board[i][j]) return false;
        }

        for(int x=0;x<9;x++){
            if(x==j) continue;
            if(board[i][x]==board[i][j]) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j){
        if(j==9){
            j=0;
            i++;
        }
        if(i==9) return true;
        if(board[i][j]!='.') {
            return solve(board,i,j+1);
        }
        for(char x='1';x<='9';x++){
            board[i][j]=x;
            if(isPossible(board,i,j)){
                if(solve(board,i,j+1)) return true;
            }
            board[i][j]='.';
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};