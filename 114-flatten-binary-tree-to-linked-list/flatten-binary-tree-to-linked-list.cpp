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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                curr=curr->right;
                continue;
            }
            //find right most guy
            TreeNode* prev=NULL;
            TreeNode* temp=curr->left;
            while(temp){
                prev=temp;
                temp=temp->right;
            }
            //connect it to curr->right
            if(prev) prev->right=curr->right;

            //remove curr->right and attatch curr->left to curr->right and move curr;
            curr->right=curr->left;
            curr->left=NULL;
            curr=curr->right;

        }
    }
};