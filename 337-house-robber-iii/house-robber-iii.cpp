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
    unordered_map<TreeNode*,unordered_map<int,int>>dp;
    int helper(TreeNode* root,int canPick){
        if(!root) return 0;
        if(dp[root].count(canPick)) return dp[root][canPick];

        int pick=0;
        if(canPick) pick=root->val+helper(root->left,0)+helper(root->right,0);
        int notPick=helper(root->left,1)+helper(root->right,1);

        return dp[root][canPick]= max(pick,notPick);

    }
    int rob(TreeNode* root) {
        return helper(root,1);
    }
};