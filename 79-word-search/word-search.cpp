class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    bool dfs(vector<vector<char>>& board,int n,int m, string word,int i,int x,int y,vector<vector<bool>>&vis){
        if(i==word.size()) return true;
        vis[x][y]=true;

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx>=0 && nx<n && ny>=0 && ny<m && word[i]==board[nx][ny] && !vis[nx][ny]){
                if(dfs(board,n,m,word,i+1,nx,ny,vis)) return true;
            }
        }
        vis[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(dfs(board,n,m,word,1,i,j,vis)) return true;
                }
            }
        }
        return false;
    }
};