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
    TreeNode* prev=NULL;
    TreeNode* first;
    TreeNode* second;
    int f=0;
    bool found=false;

    void helper(TreeNode* root){
        if(found) return;
        if(!root) return;

        helper(root->left);

        if(prev==NULL){
            prev=root;
        }
        else{
            if(root->val<=prev->val){
                if(f==0){
                    first=prev;
                    second=root;
                    f++;
                }
                else{
                    second=root;
                    f++;
                    found=true;
                }
            }
            prev=root;
        }
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val,second->val);
    }
};