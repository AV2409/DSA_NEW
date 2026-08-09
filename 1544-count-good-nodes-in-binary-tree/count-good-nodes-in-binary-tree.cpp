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
    int cnt=0;
    void helper(TreeNode* root,int maxi){
        if(!root) return;

        if(root->val>=maxi) cnt++;
        helper(root->left,max(root->val,maxi));
        helper(root->right,max(root->val,maxi));
    }
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);
        return cnt;
    }
};