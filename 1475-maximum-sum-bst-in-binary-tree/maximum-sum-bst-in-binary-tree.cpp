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
        int sum = 0;
        long long mini;
        long long maxi;
    };

    int ans = 0;
    Node helper(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Node l = helper(root->left);
        Node r = helper(root->right);

        if (l.isBst && r.isBst && root->val > l.maxi && root->val < r.mini) {
            ans = max(ans, root->val + l.sum + r.sum);
            long long mini = min((long long)root->val, l.mini);
            long long maxi = max((long long)root->val, r.maxi);

            return {true, root->val + l.sum + r.sum, mini, maxi};
            return {true, root->val + l.sum + r.sum, mini, maxi};
        }
        return {false, 0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};