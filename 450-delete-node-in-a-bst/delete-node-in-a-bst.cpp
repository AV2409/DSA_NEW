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
    TreeNode* findMax(TreeNode* root) {
        while (root->right)
            root = root->right;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;

        if (root->val > key) {
            root->left=deleteNode(root->left,key);
        } else if (root->val < key) {
            root->right=deleteNode(root->right,key);
        }
        else{
            //no child
            if(root->left==NULL && root->right==NULL) return NULL;

            //1 child
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;

            //both
            TreeNode* maxi=findMax(root->left);
            root->val=maxi->val;
            root->left=deleteNode(root->left,maxi->val);
        }
        return root;
    }
};