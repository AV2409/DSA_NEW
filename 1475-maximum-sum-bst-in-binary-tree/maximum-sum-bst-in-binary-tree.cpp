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
    struct Node {
        bool isBst;
        int sum;
        int mini;
        int maxi;
    };
    int ans = 0;
    Node helper(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Node l = helper(root->left);
        Node r = helper(root->right);

        if (l.isBst && r.isBst && root->val > l.maxi && root->val < r.mini) {
            int temp = root->val + l.sum + r.sum;
            ans = max(ans, temp);
            int mn = min(root->val, l.mini);
            int mx = max(root->val, r.maxi);
            return {true, temp, mn, mx};
        }

        return {false, 0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};