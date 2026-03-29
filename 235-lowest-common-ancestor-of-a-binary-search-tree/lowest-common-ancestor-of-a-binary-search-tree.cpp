/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int x = min(p->val, q->val);
        int y = max(p->val, q->val);

        TreeNode* head = root;

        while (head) {
            if ((head->val >= x) && (head->val <= y))
                return head;
            if (head->val > y) head=head->left;
            if (head->val < x)  head=head->right;
        }
        return NULL;
    }
};