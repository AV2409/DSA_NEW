class TrieNode {
public:
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode() {
        this->isTerminal = false;
        children.assign(2, NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        int n = word.size();
        TrieNode* temp = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - '0';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->isTerminal = true;
    }

    string findMax(string word) {
        int n = word.size();
        TrieNode* temp = root;
        string ans="";
        for (int i = 0; i < n; i++) {
            int idx = word[i] - '0';
            if (idx == 0) {
                if (temp->children[1]) {
                    temp = temp->children[1];
                    ans+='1';
                } else {
                    temp = temp->children[0];
                    ans+='0';
                }
            }
            if (idx == 1) {
                if (temp->children[0]) {
                    temp = temp->children[0];
                    ans+='1';
                } else {
                    temp = temp->children[1];
                    ans+='0';
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string numToBit(int n) {
        string ans;
        ans.assign(32, '0');
        for (int i = 0; i < 32; i++) {
            if (n & 1)
                ans[31 - i] = '1';
            else
                ans[31 - i] = '0';
            n = n / 2;
        }
        return ans;
    }

    int bitToNum(string x) {
        int ans = 0;
        long long z = 1;
        for (int i = 31; i >= 0; i--) {
            ans += z * (x[i] - '0');
            z = z * 2;
        }
        return ans;
    }

    
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        vector<string> bitNums;
        for (int x : nums) {
            string ss = numToBit(x);
            bitNums.push_back(ss);
            trie->insert(ss);
        }

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            string res = trie->findMax(bitNums[i]);
            ans = max(ans, bitToNum(res));
        }
        return ans;
    }
};