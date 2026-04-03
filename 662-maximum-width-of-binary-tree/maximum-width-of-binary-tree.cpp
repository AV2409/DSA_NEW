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
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxi = -1;
        while (!q.empty()) {
            int s = q.size();
            long long l = 0;
            long long r = 0;
            long long mini=q.front().second;
            for (int i = 0; i < s; i++) {
                auto [node,idx] = q.front();
                q.pop();
                idx-=mini;
                if(i==0) l=idx;
                r=idx;
                if(node->left) q.push({node->left,(2*idx+1)});
                if(node->right) q.push({node->right,(2*idx+2)});
                
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};