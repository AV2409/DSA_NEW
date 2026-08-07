class TrieNode{
    public:
    vector<TrieNode*>child;
    bool isT;

    TrieNode(){
        isT=false;
        child.assign(26,NULL);
    }
};


class Trie {
public:
    TrieNode* root=NULL;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(char c:word){
            int idx=c-'a';
            if(temp->child[idx]==NULL){
                temp->child[idx]=new TrieNode();
            }
            temp=temp->child[idx];
        }
        temp->isT=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(char c:word){
            int idx=c-'a';
            if(temp->child[idx]==NULL){
                return false;
            }
            temp=temp->child[idx];
        }
        return temp->isT==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(char c:prefix){
            int idx=c-'a';
            if(temp->child[idx]==NULL){
                return false;
            }
            temp=temp->child[idx];
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