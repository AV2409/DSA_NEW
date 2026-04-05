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
    struct Node {
        bool isBst;
        int sum;
        int mini;
        int maxi;
    };
    int ans=0;

    Node helper(TreeNode* root){
        if(!root) return {true,0,INT_MAX,INT_MIN};

        Node l=helper(root->left);
        Node r=helper(root->right);
        int sum=0;
        if(l.isBst && r.isBst && root->val>l.maxi && root->val<r.mini){
            sum+=root->val+l.sum+r.sum;
            ans=max(ans,sum);
            return {true,sum,min(l.mini,root->val),max(root->val,r.maxi)};
        }
        return {false,0,INT_MIN,INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};