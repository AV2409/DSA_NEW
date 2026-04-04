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
    TreeNode* w11 = NULL;
    TreeNode* w12 = NULL;
    TreeNode* w21 = NULL;
    TreeNode* w22 = NULL;
    TreeNode* prev = NULL;
    int f = 0;

    void find(TreeNode* root) {
        if (!root)
            return;
        if (f == 2)
            return;
        
        find(root->left);

        if (prev == NULL) {
            prev = root;
        } else {
            if (root->val <= prev->val) {
                if (f == 0) {
                    w11 = prev;
                    w12 = root;
                }

                if (f == 1) {
                    w21 = prev;
                    w22 = root;
                }
                f++;
            }
            prev=root;
        }
        find(root->right);
    }
    void recoverTree(TreeNode* root) {
        find(root);
        if(!w21) swap(w11->val,w12->val);
        else swap(w11->val,w22->val);

    }
};