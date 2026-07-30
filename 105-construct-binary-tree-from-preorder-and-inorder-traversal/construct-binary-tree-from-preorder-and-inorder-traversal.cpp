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
    unordered_map<int,int>mp;
    int n;
    TreeNode* build(int &idx,int st,int end,vector<int>& preorder, vector<int>& inorder){
        if(idx>=n) return NULL;
        if(st>end) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        // if(st==end) return root;
        int inord=mp[preorder[idx]];
        idx++;

        root->left=build(idx,st,inord-1,preorder,inorder);
        root->right=build(idx,inord+1,end,preorder,inorder);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        TreeNode* root=build(idx,0,n-1,preorder,inorder);
        return root;
    }
};