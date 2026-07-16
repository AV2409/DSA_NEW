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
        if(root->val==p->val || root->val==q->val) val++;
        int l=helper(root->left,p,q);
        int r=helper(root->right,p,q);

        int cnt=val+l+r;
        if(cnt==2 && ans==NULL) {
            ans=root;
            return 2;
        }
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return ans;
    }
};