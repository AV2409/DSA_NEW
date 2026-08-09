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
    int findMin(TreeNode* root){
        TreeNode* curr=root;
        while(curr->left){
            curr=curr->left;
        }
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{

            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            if(root->left == NULL || root->right == NULL){
                if(root->left) return root->left;
                return root->right;
            }
            int mini=findMin(root->right);
            root->val=mini;
            root->right=deleteNode(root->right,mini);
        }
        return root;
    }
};