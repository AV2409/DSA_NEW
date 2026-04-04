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
    int ans = 0;
    // {isBST, sum, minVal, maxVal}
    vector<int> isBst(TreeNode* root) {
        if (!root)
            return {1, 0, INT_MAX, INT_MIN};
        auto l = isBst(root->left);
        auto r = isBst(root->right);
        if (l[0] && r[0] && root->val > l[3] && root->val < r[2]) {
            int sum = root->val + l[1] + r[1];
            ans = max(ans, sum);

            int mini = min({root->val, l[2],r[2]});
            int maxi = max({root->val, r[3],l[3]});

            return {1, sum, mini, maxi};
        }

        return {0, 0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        isBst(root);
        if (ans == -1e9)
            return 0;
        return ans;
    }
};