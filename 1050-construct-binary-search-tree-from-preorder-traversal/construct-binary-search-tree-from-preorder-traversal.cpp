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
    TreeNode* build(int &idx,vector<int>& preorder,int mini,int maxi){
        if(idx==preorder.size()) return NULL;
        if(preorder[idx]<=mini||preorder[idx]>=maxi) return NULL;

        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=build(idx,preorder,mini,root->val);
        root->right=build(idx,preorder,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build(idx,preorder,INT_MIN,INT_MAX);
    }
};