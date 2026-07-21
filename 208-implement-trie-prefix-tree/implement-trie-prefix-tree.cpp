class TrieNode{
public:
    TrieNode* children[26];
    bool terminal;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        terminal=false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(char ch:word){
            int idx=ch-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=new TrieNode();
            }
            temp=temp->children[idx];
        }
        temp->terminal=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(char ch:word){
            int idx=ch-'a';
            if(temp->children[idx]==NULL){
                return false;
            }
            temp=temp->children[idx];
        }
        return temp->terminal==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(char ch:prefix){
            int idx=ch-'a';
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