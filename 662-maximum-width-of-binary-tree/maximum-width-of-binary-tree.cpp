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
        q.push({root, 1});
        long long ans = 0;
        while (!q.empty()) {
            int ss = q.size();
            long long l;
            long long r;
            int minIdx=q.front().second;
            for (int i = 0; i < ss; i++) {
                auto [node, idx] = q.front();
                idx=idx-minIdx;
                q.pop();
                if(i==0) l=idx;
                if(i==ss-1) r=idx;
                if (node->left)
                    q.push({node->left, 2 * idx});
                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};