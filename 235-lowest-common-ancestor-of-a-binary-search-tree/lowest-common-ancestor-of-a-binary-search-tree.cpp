/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root, int mini, int maxi, TreeNode*& ans) {
        if (!root || ans != NULL)
            return;

        if (root->val >= mini && root->val <= maxi) {
            ans = root;
            return;
        }
        if (root->val < mini) {
            helper(root->right, mini, maxi, ans);
        }
        if (root->val > maxi) {
            helper(root->left, mini, maxi, ans);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = p->val;
        int y = q->val;

        int mini = min(x, y);
        int maxi = max(x, y);
        while (root) {
            if (root->val >= mini && root->val <= maxi) {
                return root;
            }
            if (root->val < mini) {
                root=root->right;
            }
            if (root->val > maxi) {
                root=root->left;
            }
        }
        return root;
    }
};