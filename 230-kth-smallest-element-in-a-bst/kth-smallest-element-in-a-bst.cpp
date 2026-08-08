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
    bool found=false;
    int ans=-1;
    int K;
    void helper(TreeNode* root){
        if(!root) return;
        if(found) return;
        helper(root->left);
        K--;
        if(K==0 && ans==-1){
            ans=root->val;
            found=true;
        }
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        helper(root);
        return ans;
    }
};