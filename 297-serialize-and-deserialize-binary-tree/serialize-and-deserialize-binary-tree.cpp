/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void trav(TreeNode* root, string& ans) {
        if (!root) {
            ans += "n,";
            return;
        }
        ans += to_string(root->val);
        ans += ",";
        trav(root->left, ans);
        trav(root->right, ans);
    }
    string serialize(TreeNode* root) {

        if (!root)
            return "n";
        string ans = "";
        trav(root, ans);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* build(vector<string>& vals, int& idx) {
        if (idx >= vals.size())
            return NULL;
        if (vals[idx] == "n") {
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(vals[idx]));
        idx++;

        root->left = build(vals, idx);
        root->right = build(vals, idx);

        return root;
    }
    TreeNode* deserialize(string data) {
        if (data == "n")
            return NULL;
        vector<string> vals;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                vals.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int idx = 0;
        TreeNode* root = build(vals, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));