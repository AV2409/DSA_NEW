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
    string findMax(string& num) {
        string ans;
        TrieNode* temp = root;
        for (char c : num) {
            int idx = c - '0';
            int toggled = 1 - idx;

            if (temp->children[toggled]) {
                ans.push_back('1');
                temp = temp->children[toggled];
            } else {
                ans.push_back('0');
                temp = temp->children[idx];
            }
        }
        return ans;
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

    int bitToNum(string& s) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (s[i] - '0');
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string> bits;
        for (int n : nums) {
            bits.push_back(numToBits(n));
            // cout<<bits.back()<<" ";
        }

        for (string n : bits) {
            insert(n);
        }
        int ans = -1;
        for (string n : bits) {
            string ansStr = findMax(n);
            ans = max(ans, bitToNum(ansStr));
        }
        return ans;
    }
};