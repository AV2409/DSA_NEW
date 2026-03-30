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
    void helper(TreeNode* root, int &cnt,int& mini) {
        if (root == NULL)
            return;
        cnt++;
        if (root->left == NULL && root->right == NULL) {
            mini = min(mini, cnt);
        } else {
            helper(root->left, cnt, mini);
            helper(root->right, cnt, mini);
        }
        cnt--;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int cnt=0;
        int mini=INT_MAX;
        helper(root,cnt,mini);
        return mini;
    }
};