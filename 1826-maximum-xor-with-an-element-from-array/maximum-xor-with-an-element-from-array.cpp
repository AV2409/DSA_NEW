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

    int findMax(string word) {
        int n = word.size();
        TrieNode* temp = root;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans <<= 1;
            int idx = word[i] - '0';
            if (idx == 0) {
                if (temp->children[1]) {
                    temp = temp->children[1];
                    ans |= 1;
                } else if (temp->children[0]) {
                    temp = temp->children[0];
                } else
                    break;
            }
            if (idx == 1) {
                if (temp->children[0]) {
                    temp = temp->children[0];
                    ans |= 1;
                } else if (temp->children[1]) {
                    temp = temp->children[1];
                } else
                    break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

    string numToBit(int n) {
        string ans;
        ans.assign(32, '0');
        for (int i = 0; i < 32; i++) {
            if (n & 1)
                ans[31 - i] = '1';
            else
                ans[31 - i] = '0';
            n = n / 2;
            if (n == 0)
                break;
        }
        return ans;
    }

    int bitToNum(string x) {
        int ans = 0;
        for (char c : x) {
            ans <<= 1;
            ans |= (c - '0');
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* trie = new Trie();
        sort(nums.begin(), nums.end());
        int qs = queries.size();
        vector<int> ans(qs, 0);
        int numsIdx = 0;
        int i = 0;
        for (auto& q : queries) {
            q.push_back(i);
            i++;
        }
        vector<string> bitNums;
        for (int x : nums) {
            string s = numToBit(x);
            bitNums.push_back(s);
        }
        sort(queries.begin(), queries.end(), comp);
        int n = nums.size();
        for (auto& q : queries) {
            int num = q[0];
            int maxi = q[1];
            int idx = q[2];

            while (numsIdx < n && nums[numsIdx] <= maxi) {
                trie->insert(bitNums[numsIdx]);
                numsIdx++;
            }

            if (trie->root->children[0] == NULL &&
                trie->root->children[1] == NULL) {
                ans[idx] = -1;
                continue;
            }

            string strNum = numToBit(num);
            int res = trie->findMax(strNum);
            ans[idx] = res;
        }
        return ans;
    }
};