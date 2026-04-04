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
        bool flag=false;
        while(true){
            if(temp->val>val){
                if(temp->left) temp=temp->left;
                else {
                    temp->left=node;
                    flag=true;
                }
            }
            if(temp->val<val){
                if(temp->right) temp=temp->right;
                else{
                    temp->right=node;
                    flag=true;
                }
            }
            if(flag) break;
        }
        return root;
    }
};