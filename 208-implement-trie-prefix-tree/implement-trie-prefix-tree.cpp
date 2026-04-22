class Node{
public:
    char data;
    Node* children[26];
    bool isTerminal;

    Node(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root= new Node('\0');
    }

    void insertHelper(Node* root,string word){
        if(word.size()==0) {
            root->isTerminal=true;
            return;
        }

        int idx=word[0]-'a';
        Node* child;
        if(root->children[idx]){
            child=root->children[idx];
        }
        else{
            child=new Node(word[0]);
            root->children[idx]=child;
        }
        insertHelper(child,word.substr(1));
    }
    
    void insert(string word) {
        insertHelper(root,word);
    }

    bool searchHelper(Node* root,string word){
        if(word.size()==0) return root->isTerminal;

        int idx=word[0]-'a';
        
        if(!root->children[idx]){
            return false;
        }
        Node* child=root->children[idx];
        return searchHelper(child,word.substr(1));
    }
    
    bool search(string word) {
        return searchHelper(root,word);
    }

    bool startsWithHelper(Node* root,string word){
        if(word.size()==0) return true;

        int idx=word[0]-'a';
        
        if(!root->children[idx]){
            return false;
        }
        Node* child=root->children[idx];
        return startsWithHelper(child,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */