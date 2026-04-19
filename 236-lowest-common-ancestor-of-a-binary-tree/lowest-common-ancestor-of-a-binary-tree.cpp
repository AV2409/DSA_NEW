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
    TreeNode* ans=NULL;

    int helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(ans) return 2;
        if(!root) return 0;

        int val=0;
        if(root==p||root==q) val=1;
        int l=helper(root->left,p,q);
        int r=helper(root->right,p,q);

        if(val+l+r==2 && ans==NULL) ans=root;
        return val+l+r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return ans;
    }
};