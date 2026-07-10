class TrieNode {
public:
    vector<TrieNode*> children;
    bool isTerminal;
    string word;
    TrieNode() {
        this->isTerminal = false;
        children.assign(26, NULL);
        word="";
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        int n = word.size();
        TrieNode* temp = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = new TrieNode();
            }
            string prevWord=temp->word;
            temp = temp->children[idx];
            temp->word=prevWord+word[i];
        }
        temp->isTerminal = true;
    }
    
    vector<string>ans;
    int n;
    int m;
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    void dfs(int x,int y,TrieNode* temp,vector<vector<char>>& board){
        if(temp->isTerminal){
            ans.push_back(temp->word);
            temp->isTerminal = false;
        }
        char ch=board[x][y];
        board[x][y]='#';

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]!='#'){
                int idx=board[nx][ny]-'a';
                if(temp->children[idx]){
                    dfs(nx,ny,temp->children[idx],board);
                }
            }
        }
        board[x][y]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (string x : words) {
            insert(x);
        }

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = board[i][j] - 'a';
                if (root->children[idx] != NULL) {
                    TrieNode* temp=root->children[idx];
                    dfs(i, j,temp, board);
                }
            }
        }
        return ans;
    }
};