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
    bool ans=true;
    TreeNode* prev=NULL;

    void helper(TreeNode* root){
        if(!root) return;

        helper(root->left);
        if(prev && root->val<=prev->val) ans=false;
        prev=root;
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};