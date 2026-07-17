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
        vector<TreeNode*> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr);
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
                if (prev->right == NULL) {
                    prev->right = curr;
                    ans.push_back(curr);
                    curr = curr->left;
                }

                // if already connected
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        int n = ans.size();
        for (int i = 0; i < n - 1; i++) {
            TreeNode* prev = ans[i];
            TreeNode* next = ans[i + 1];
            prev->right = next;
            prev->left = NULL;
        }
        if (n > 0) {
            ans[n - 1]->left = NULL;
            ans[n - 1]->right = NULL;
        }
    }
};