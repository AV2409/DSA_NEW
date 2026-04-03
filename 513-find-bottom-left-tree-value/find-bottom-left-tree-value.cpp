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
    void helper(TreeNode* root,int lvl,int &maxi,int &ans){
        if(!root) return;
        if(lvl>maxi) {
            ans=root->val;
            maxi=lvl;
        }
        helper(root->left,lvl+1,maxi,ans);
        helper(root->right,lvl+1,maxi,ans);

    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val;
        int maxi=-1;
        helper(root,0,maxi,ans);
        return ans;
    }
};