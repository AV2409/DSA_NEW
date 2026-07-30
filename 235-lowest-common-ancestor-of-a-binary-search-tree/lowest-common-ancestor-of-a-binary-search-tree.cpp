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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        long long mini=min(p->val,q->val);
        long long maxi=max(p->val,q->val);

        TreeNode* curr=root;
        while(curr){
            if(curr->val<mini) curr=curr->right;
            else if(curr->val>maxi) curr=curr->left;
            else return curr;
        }
        return NULL;

    }
};