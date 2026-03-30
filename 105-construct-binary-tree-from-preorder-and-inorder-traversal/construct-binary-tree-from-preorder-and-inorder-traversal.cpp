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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp,int &idx,int low,int high){
        if (low > high) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        int i=mp[preorder[idx]];
        idx++;
        root->left=build(preorder,inorder,mp,idx,low,i-1);
        root->right=build(preorder,inorder,mp,idx,i+1,high);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx=0;

        return build(preorder,inorder,mp,idx,0,inorder.size()-1);
    }
};