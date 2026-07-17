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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        // vector<TreeNode*> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == NULL) {
                curr = curr->right;
            }

            else {
                // find rightmost guy on left
                TreeNode* temp = curr->left;
                TreeNode* prev = curr->left;
                while (temp && temp != curr) {
                    prev = temp;
                    temp = temp->right;
                }

                // connect that guy to the root/curr
                // creating thread

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr=curr->right;
            }
        }
    }
};