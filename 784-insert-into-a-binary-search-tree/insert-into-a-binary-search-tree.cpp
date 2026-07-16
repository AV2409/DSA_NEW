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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(!root) return node;
        TreeNode* temp=root;
        TreeNode* prev=root;

        while(temp){
            prev=temp;
            if(temp->val>val) temp=temp->left;
            else if(temp->val<val) temp=temp->right;
        }
        // cout<<prev->val;
        if(val<prev->val)
            prev->left=node;
        else prev->right=node;
        return root;
    }
};