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
    bool check(TreeNode* root, int targetSum){
        if(!root->left && !root->right){
            return targetSum==root->val;
        }

        bool l=false;
        bool r=false;
        if(root->left) l=check(root->left,targetSum-root->val);
        if(root->right) r=check(root->right,targetSum-root->val);

        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return check(root,targetSum);
    }
};