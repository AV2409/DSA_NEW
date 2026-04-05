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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans=0;

        while (!q.empty()) {
            int s = q.size();
            long long l = 0;
            long long r = 0;
            int mini=q.front().second;
            for (int i = 0; i < s; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx-=mini;
                if (node->left)
                    q.push({node->left, 2 * idx + 1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
                if (i == 0)
                    l = idx;
                r =idx;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};