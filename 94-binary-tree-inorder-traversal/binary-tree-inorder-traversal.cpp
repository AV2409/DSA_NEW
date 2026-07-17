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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }

            else {
                // find rightmost guy on left
                TreeNode* temp = curr->left;
                TreeNode* prev = curr->left;
                while (temp && temp!=curr) {
                    prev = temp;
                    temp = temp->right;
                }

                // connect that guy to the root/curr
                //creating thread
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr=curr->left;
                }

                //if already connected
                else{
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};