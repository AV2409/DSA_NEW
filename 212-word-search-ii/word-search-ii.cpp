class TrieNode{
    public:
    bool isT;
    string word;
    vector<TrieNode*>child;

    TrieNode(){
        child.assign(26,nullptr);
        isT=false;
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    vector<string>ans;
    int m;
    int n;

    void insert(string &w){
        TrieNode* curr=root;
        for(char c:w){
            int idx=c-'a';
            if(!curr->child[idx]){
                curr->child[idx]=new TrieNode();
            }
            curr=curr->child[idx];
        }
        curr->isT=true;
        curr->word=w;
    }
    vector<int>dx={0,0,-1,1};
    vector<int>dy={1,-1,0,0};
    void dfs(int i,int j,TrieNode* curr,vector<vector<char>>& board){
        char temp=board[i][j];
        board[i][j]='.';
        if(curr->isT){
            ans.push_back(curr->word);
            curr->isT=false;
        }

        for(int dir=0;dir<4;dir++){
            int nx=i+dx[dir];
            int ny=j+dy[dir];

            if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]!='.'){
                int idx=board[nx][ny]-'a';
                if(curr->child[idx])
                    dfs(nx,ny,curr->child[idx],board);

            }
        }

        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string &w:words) insert(w);
        TrieNode* curr=root;
        m=board.size();
        n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=board[i][j]-'a';
                if(curr->child[idx])
                    dfs(i,j,curr->child[idx],board);
            }
        }
        return ans;

    }
};