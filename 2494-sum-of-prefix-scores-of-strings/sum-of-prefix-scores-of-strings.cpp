class TrieNode {
public:
    TrieNode* children[26];
    int cnt=0;
    TrieNode() {
        for(int i=0;i<26;i++) children[i]=NULL;
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
            temp->cnt++;
        }
    }

    int search(string word) {
        int n=word.size();
        TrieNode* temp=root;
        int x=0;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(temp->children[idx]==NULL){
                return x;
            }
            temp=temp->children[idx];
            x+=temp->cnt;
        }
        return x;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie=new Trie();

        for(string &w:words){
            trie->insert(w);
        }

        vector<int>ans;

        for(string &w:words){
            int x=trie->search(w);
            ans.push_back(x);
        }
        return ans;
    }
};