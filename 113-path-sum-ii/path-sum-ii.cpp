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
    void helper(TreeNode* root, int targetSum,vector<int>&path,vector<vector<int>>&ans){
        int val=root->val;
        path.push_back(root->val);
        targetSum-=val;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==0) {
                ans.push_back(path);
                path.pop_back();
                return;
            }
        }

        if(root->left){
            helper(root->left,targetSum,path,ans);
        }
        if(root->right){
            helper(root->right,targetSum,path,ans);
        }
        targetSum+=val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>ans;
        if(!root) return ans;
        helper(root,targetSum,path,ans);
        return ans;
    }
};