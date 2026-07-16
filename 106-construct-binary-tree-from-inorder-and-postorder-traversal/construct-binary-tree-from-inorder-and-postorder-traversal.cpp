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
    TreeNode* build(int &idx,int low,int high,vector<int>& postorder, vector<int>& inorder){
        if(low>high) return NULL;
        if(idx<0) return NULL;
        TreeNode* root=new TreeNode(postorder[idx]);

        int inIdx=mp[postorder[idx]];
        idx--;
        root->right=build(idx,inIdx+1,high,postorder,inorder);
        root->left=build(idx,low,inIdx-1,postorder,inorder);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }

        int idx=n-1;

        return build(idx,0,n-1,postorder,inorder);
    }
};