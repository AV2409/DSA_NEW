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

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(ans) return ans;
        if(!root) return NULL;
        
        TreeNode* l=lca(root->left,p,q,ans);
        TreeNode* r=lca(root->right,p,q,ans);
        TreeNode* temp=NULL;
        if(root==p || root==q){
            temp=root;
        }

        if((temp&&l)||(temp&&r)){
            if(ans==NULL) ans=temp;
            return temp;
        }
        if(l&&r) {
            if(ans==NULL) ans=root;
            return root;
        }

        if(temp) return temp;
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;

        lca(root,p,q,ans);
        return ans;
    }
};