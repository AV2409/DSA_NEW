class TrieNode{
    public:
    vector<TrieNode*>child;

    TrieNode(){
        child.assign(2,NULL);
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    void insert(string &word) {
        TrieNode* temp=root;
        for(char c:word){
            int idx=c-'0';
            if(temp->child[idx]==NULL){
                temp->child[idx]=new TrieNode();
            }
            temp=temp->child[idx];
        }
    }
    int find(string &word) {
        TrieNode* temp=root;
        int res=0;
        for(int i=0;i<32;i++){
            int idx=word[i]-'0';
            int inv=1-idx;
            if(temp->child[inv]){
                res<<=1;
                res|=1;
                temp=temp->child[inv];
            }
            else {
                res<<=1;
                temp=temp->child[idx];
            }
        }
        return res;
    }
    string toBit(int num){
        string ans(32,'0');
        int idx=31;
        while(num>0){
            int dig=num&1;
            if(dig) ans[idx]='1';
            num>>=1;
            idx--;
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string>strs;
        for(int x:nums){
            strs.push_back(toBit(x));
        }
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            insert(strs[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,find(strs[i]));
        }
        return ans;
    }
};