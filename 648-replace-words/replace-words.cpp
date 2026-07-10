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

    string search(string word) {
        int n=word.size();
        TrieNode* temp=root;
        string x="";
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            
            if(temp->isTerminal) return x;
            x+=word[i];
            if(temp->children[idx]==NULL){
                return word;
            }
            temp=temp->children[idx];
        }
        return word;
    }
};

class Solution {
public:
    Trie* trie=new Trie();
    string find(string word){
        return trie->search(word);
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        for(string w:dictionary){
            trie->insert(w);
        }

        vector<string>words;
        int n=sentence.size();
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && sentence[i]!=' '){
                temp+=sentence[i];
                i++;
            }
            words.push_back(temp);
        }
        
        string ans;
        for(string word:words){
            string x=find(word);
            ans+=x;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};