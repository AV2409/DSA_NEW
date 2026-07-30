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
    int n;
    TreeNode* build(int &idx,long long mini,long long maxi,vector<int>& preorder){
        if(idx>=n) return NULL;
        if(preorder[idx]<=mini||preorder[idx]>=maxi) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=build(idx,mini,root->val,preorder);
        root->right=build(idx,root->val,maxi,preorder);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n=preorder.size();
        int idx=0;
        TreeNode* root=build(idx,LLONG_MIN,LLONG_MAX,preorder);
        return root;
    }
};