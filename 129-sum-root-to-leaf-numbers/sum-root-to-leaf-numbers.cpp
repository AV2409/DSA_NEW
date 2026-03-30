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
    void check(TreeNode* root, int &temp,int &sum) {
        if (root == NULL)
            return;
        
        temp=temp*10+root->val;
        if (!root->left && !root->right) {
            sum+=temp;
        } else {
            check(root->left, temp, sum);
            check(root->right, temp, sum);
        }

        temp=temp/10;
    }
    int sumNumbers(TreeNode* root) {
        int temp=0;
        int sum=0;
        check(root,temp,sum);
        return sum;
    }
};