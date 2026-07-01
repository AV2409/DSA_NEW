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
        int val=root->val;
        targetSum-=val;
        if(!root->left && !root->right){
            return targetSum==0;
        }

        bool l=false;
        bool r=false;

        if(root->left) l=check(root->left,targetSum);
        if(root->right) r=check(root->right,targetSum);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return check(root,targetSum);
    }
};