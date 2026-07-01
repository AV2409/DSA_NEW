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
    int ans = -1;
    int helper(TreeNode* root) {
        if (!root)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        int leftPath = 0, rightPath = 0;

        if (root->left && root->left->val == root->val)
            leftPath = left;

        if (root->right && root->right->val == root->val)
            rightPath = right;

        ans = max(ans, leftPath + rightPath);

        return 1+max(leftPath, rightPath);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return ans;
    }
};