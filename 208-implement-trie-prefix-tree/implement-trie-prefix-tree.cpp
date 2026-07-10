class TrieNode {
public:
    vector<TrieNode*>children;
    bool isTerminal;

    TrieNode() {
        this->isTerminal=false;
        children.assign(26,NULL);
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }

    void insert(string word) {
        int n=word.size();
        TrieNode* temp=root;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=new TrieNode();
            }
            temp=temp->children[idx];
        }
        temp->isTerminal=true;
    }

    bool search(string word) {
        int n=word.size();
        TrieNode* temp=root;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(temp->children[idx]==NULL){
                return false;
            }
            temp=temp->children[idx];
        }
        return temp->isTerminal==true;
    }

    bool startsWith(string prefix) {
        int n=prefix.size();
        TrieNode* temp=root;
        for(int i=0;i<n;i++){
            int idx=prefix[i]-'a';
            if(temp->children[idx]==NULL){
                return false;
            }
            temp=temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */