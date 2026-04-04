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
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                q.push(curr);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }
                if (temp->right == NULL) {
                    temp->right = curr;
                    q.push(curr);
                    curr = curr->left;
                } else if (temp->right == curr) {
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        if(q.empty()) return;
        root=q.front();
        q.pop();
        TreeNode* c=root;
        c->left=NULL;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            c->right=node;
            c->left=NULL;
            c=node;
        }
    }
};