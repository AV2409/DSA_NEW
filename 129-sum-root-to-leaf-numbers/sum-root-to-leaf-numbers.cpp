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
    void check(TreeNode* root, int &temp,
               vector<int>& ans) {
        if (root == NULL)
            return;
        
        temp=temp*10+root->val;
        if (!root->left && !root->right) {
            ans.push_back(temp);
        } else {
            check(root->left, temp, ans);
            check(root->right, temp, ans);
        }

        temp=temp/10;
    }
    int sumNumbers(TreeNode* root) {
        vector<int>ans;
        int temp=0;
        check(root,temp,ans);
        int sum=0;
        for(int x:ans){
            sum+=x;
        }
        return sum;
    }
};