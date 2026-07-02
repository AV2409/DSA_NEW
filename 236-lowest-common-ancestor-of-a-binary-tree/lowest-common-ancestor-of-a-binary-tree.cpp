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
        if(!root) return 0;
        if(ans) return 0;

        int cnt=0;
        if(root==p||root==q) cnt++;
        int left=helper(root->left,p,q);
        int right=helper(root->right,p,q);
        cnt+=left+right;
        

        if(cnt==2 && ans==NULL){
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