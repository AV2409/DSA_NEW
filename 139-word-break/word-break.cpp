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

class Solution {
public:
    TrieNode* root=new TrieNode();
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
    unordered_map<int,unordered_map<TrieNode*,bool>>mp;
    bool find(int idx,TrieNode* head,string &s){
        if(idx==s.size()) return head == root || head->terminal;
        if (mp[idx].count(head))
            return mp[idx][head];
        int i=s[idx]-'a';
        if(head->children[i]==NULL) return false;

        TrieNode* temp=head->children[i];
        //start from root;
        bool op1=false;
        if(temp->terminal) op1=find(idx+1,root,s);
        bool op2=find(idx+1,temp,s);
        return mp[idx][head]= op1||op2;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &w:wordDict){
            insert(w);
        }

        return find(0,root,s);
    }
};