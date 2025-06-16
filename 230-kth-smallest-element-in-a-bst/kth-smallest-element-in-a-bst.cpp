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
    void find(TreeNode* root, int k,int &cnt,vector<int> &ans){
        if(root==NULL){
            return;
        }

        find(root->left,k,cnt,ans);
        ans.push_back(root->val);
        find(root->right,k,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        int cnt=0;
        find(root,k,cnt,ans);
        return ans[k-1];
    }
};