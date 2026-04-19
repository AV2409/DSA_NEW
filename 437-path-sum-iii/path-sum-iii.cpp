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
    unordered_map<long long, int> prefix;
    int helper(TreeNode* root,long long curr, int targetSum) {
        if(!root) return 0;
        curr+=root->val;
        int res=0;

        if(prefix.count(curr-targetSum)){
            res+=prefix[curr-targetSum];
        }

        prefix[curr]++;

        res+=helper(root->left,curr,targetSum);
        res+=helper(root->right,curr,targetSum);

        prefix[curr]--;
        return res;

    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return helper(root,0,targetSum);
    }
};