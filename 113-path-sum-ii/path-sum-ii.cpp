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
    void check(TreeNode* root, int targetSum, int& sum, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (root == NULL)
            return;
        sum += root->val;
        temp.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == targetSum) {
                ans.push_back(temp);
            }
        } else {
            check(root->left, targetSum, sum, temp, ans);
            check(root->right, targetSum, sum, temp, ans);
        }

        sum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        check(root, targetSum, sum, temp, ans);
        return ans;
    }
};