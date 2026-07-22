class TrieNode {
public:
    TrieNode* children[2];
    bool terminal;
    TrieNode() {
        for (int i = 0; i < 2; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    int ans=-1;
    void insert(string& num) {
        TrieNode* temp = root;
        for (char c : num) {
            int idx = c - '0';
            if (temp->children[idx] == NULL) {
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
    }
    void findMax(string& num) {
        // string ans;
        int res=0;
        TrieNode* temp = root;
        for (char c : num) {
            int idx = c - '0';
            int toggled = 1 - idx;
            res=res<<1;
            if (temp->children[toggled]) {
                res|=1;
                temp = temp->children[toggled];
            } else {
                res|=0;
                temp = temp->children[idx];
            }
        }
        ans=max(ans,res);
    }
    string numToBits(int n) {
        string ans(32, '0');
        int i = 31;
        while (n > 0) {
            int rem = n % 2;
            n /= 2;
            ans[i] = rem + '0';
            i--;
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        vector<string> bits;
        for (int n : nums) {
            bits.push_back(numToBits(n));
        }

        for (string n : bits) {
            insert(n);
        }
        for (string n : bits) {
            findMax(n);
        }
        return ans;
    }
};