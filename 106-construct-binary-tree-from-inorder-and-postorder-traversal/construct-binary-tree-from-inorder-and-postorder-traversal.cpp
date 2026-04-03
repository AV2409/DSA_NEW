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
    TreeNode* build(vector<int>& postorder,int &idx,int low,int high,unordered_map<int,int>&mp){
        if(low>high) return NULL;

        TreeNode* root=new TreeNode(postorder[idx]);
        int i=mp[postorder[idx]];
        idx--;

        root->right=build(postorder,idx,i+1,high,mp);
        root->left=build(postorder,idx,low,i-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int idx=n-1;
        TreeNode* root=build(postorder,idx,0,n-1,mp);
        return root;
    }
};