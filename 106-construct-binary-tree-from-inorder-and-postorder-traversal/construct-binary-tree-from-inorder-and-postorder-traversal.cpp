/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& mp,
                    int& idx, int low, int high) {
        if (low > high)
            return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        int i = mp[postorder[idx]];
        idx--;
        
        root->right = build(postorder, mp, idx, i + 1, high);
        root->left = build(postorder, mp, idx, low, i - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx = postorder.size()-1;

        return build(postorder, mp, idx, 0, inorder.size() - 1);
    }
};