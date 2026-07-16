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
    void helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return;
        if(ans) return;
        int maxi=max(p->val,q->val);
        int mini=min(p->val,q->val);

        if(root->val>maxi) helper(root->left,p,q);
        else if(root->val<mini) helper(root->right,p,q);
        else{
            if(!ans) ans=root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return ans;
    }
};