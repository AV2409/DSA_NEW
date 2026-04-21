/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd, int &idx, unordered_map<int,int>& mp) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];

        root->left = build(preorder, inStart, pos - 1, idx, mp);
        root->right = build(preorder, pos + 1, inEnd, idx, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();
        unordered_map<int,int> mp;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1, idx, mp);
    }
};
