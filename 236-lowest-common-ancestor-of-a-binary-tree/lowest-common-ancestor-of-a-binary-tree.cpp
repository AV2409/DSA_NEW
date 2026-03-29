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
    int helper(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(ans) return 2;
        if(root==NULL) return 0;

        int l=helper(root->left,p,q,ans);
        int r=helper(root->right,p,q,ans);
        int s=0;
        if(root==p||root==q){
            s=1;
        }

        if((l+r+s)==2&&ans==NULL){
            ans=root;
        }

        return l+r+s;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        int temp=helper(root,p,q,ans);
        return ans;
    }
};