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

    bool check(TreeNode* root1, TreeNode* root2){
        if(root1==NULL||root2==NULL){
            return root1==root2;
        }

        if(root1->val!=root2->val) return false;
        bool l1=check(root1->left,root2->left);
        bool r1=check(root1->right,root2->right);

        bool l2=check(root1->left,root2->right);
        bool r2=check(root1->right,root2->left);

        return (l1&&r1) || (l2&&r2);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);
    }
};