class Solution {
public:
    int m;
    int n;
    int ss;
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    bool dfs(int i,int x,int y,vector<vector<char>>& board, string &word){
        if(i==ss) return true;
        char temp=board[x][y];
        board[x][y]='.';
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]==word[i]){
                if(dfs(i+1,nx,ny,board,word)) return true;
            }
        }
        board[x][y]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();

        ss=word.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(1,i,j,board,word)) return true;
                }
            }
        }
        return false;
        
    }
};