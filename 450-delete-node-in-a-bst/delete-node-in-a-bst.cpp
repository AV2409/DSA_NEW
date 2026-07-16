/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findMin(TreeNode* root){
        TreeNode* temp=root;
        while(temp->left){
            temp=temp->left;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if (root->val > key){
            root->left=deleteNode(root->left,key);
        }
        else if (root->val < key){
            root->right=deleteNode(root->right,key);
        }
            
        else {
            //0 child
            if (root->right==NULL && root->left==NULL) {
                delete root;
                return NULL;
            }

            //1 child
            if (root->right==NULL || root->left==NULL) {
                if(root->left) return root->left;
                return root->right;
            }

            //2 child
            int mini=findMin(root->right);

            root->val=mini;
            root->right=deleteNode(root->right,mini);

        }
        return root;
    }
};