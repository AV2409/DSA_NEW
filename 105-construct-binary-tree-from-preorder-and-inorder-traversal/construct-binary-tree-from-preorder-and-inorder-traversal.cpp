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

    TreeNode* build(vector<int>& preorder,int& preIdx,int l,int h,unordered_map<int,int>&mp){
        if(l>h) return NULL;
        TreeNode* root=new TreeNode(preorder[preIdx]);
        int idx=mp[preorder[preIdx]];
        preIdx++;

        root->left=build(preorder,preIdx,l,idx-1,mp);
        root->right=build(preorder,preIdx,idx+1,h,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int preIdx=0;
        TreeNode* root=build(preorder,preIdx,0,n-1,mp);
        return root;
    }
};