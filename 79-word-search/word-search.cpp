class Solution {
public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};

    bool dfs(int x, int y, int i, vector<vector<char>>& board,int m,int n, string word) {
        if (i == word.size())
            return true;
        
        char temp = board[x][y];
        board[x][y] = '.';
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && ny < n && nx < m && board[nx][ny] == word[i]) {
                if(dfs(nx, ny, i+1, board,m,n, word)) return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string &word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,1,board,m,n,word)) return true;
                }
            }
        }
        return false;
    }
};