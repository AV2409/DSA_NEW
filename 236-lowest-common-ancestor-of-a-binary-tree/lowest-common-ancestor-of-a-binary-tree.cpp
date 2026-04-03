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

    int lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(!root) return 0;
        int val=0;
        if(root==p || root==q){
            val=1;
        }
        int l=lca(root->left,p,q,ans);
        int r=lca(root->right,p,q,ans);
        if(val+l+r==2&& ans==NULL) ans=root;
        return val+l+r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;

        lca(root,p,q,ans);
        return ans;
    }
};