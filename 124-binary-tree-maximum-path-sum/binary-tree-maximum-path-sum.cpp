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
    int find(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }

        int l=max(0,find(root->left,maxi));
        int r=max(0,find(root->right,maxi));

        maxi=max(maxi,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int x=find(root,maxi);
        return maxi;
    }
};