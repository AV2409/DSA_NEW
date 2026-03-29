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
    void find(TreeNode* root, int k,int &ans,int &cnt){
        if(root==NULL||ans!=-1){
            return;
        }

        find(root->left,k,ans,cnt);
        cnt++;
        if(cnt==k) {
            ans=root->val;
            return;
        }
        find(root->right,k,ans,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        find(root,k,ans,cnt);
        return ans;
    }
};