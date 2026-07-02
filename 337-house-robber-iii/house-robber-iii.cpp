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
    unordered_map<TreeNode*, int> canPickDP;
    unordered_map<TreeNode*, int> cannotPickDP;

    int solve(TreeNode* root, bool canPick) {
        if (!root)
            return 0;
        if (canPick) {
            if (canPickDP.count(root))
                return canPickDP[root];
        } else {
            if (cannotPickDP.count(root))
                return cannotPickDP[root];
        }
        int pick = 0;
        int notpick = 0;
        // can pick
        if (canPick) {
            int left = solve(root->left, false);
            int right = solve(root->right, false);
            pick = root->val + left + right;
        }
        // cannot pick
        int left = solve(root->left, true);
        int right = solve(root->right, true);
        notpick = left + right;

        if (canPick) {
            return canPickDP[root] = max(pick, notpick);
        }
        return cannotPickDP[root] = max(pick, notpick);
    }
    int rob(TreeNode* root) { return solve(root, true); }
};