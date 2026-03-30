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

    bool check(TreeNode* root, int targetSum,int &sum){
        if(root==NULL) return false;
        sum+=root->val;

        if(!root->left && !root->right){
            if(sum==targetSum) return true;
        }
        bool l=check(root->left,targetSum,sum);
        bool r=check(root->right,targetSum,sum);
        sum-=root->val;

        return l||r;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if(!root) return false;
        return check(root,targetSum,sum);
    }
};