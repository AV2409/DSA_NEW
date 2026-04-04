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

    TreeNode* build(vector<int>& preorder,int &idx,int mini,int maxi){
        if(idx>=preorder.size()) return NULL;
        int val=preorder[idx];
        if(val<=mini||val>=maxi) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=build(preorder,idx,mini,root->val);
        root->right=build(preorder,idx,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        TreeNode* root=build(preorder,idx,INT_MIN,INT_MAX);
        return root;
    }
};