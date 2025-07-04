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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }

    TreeNode* buildBST(int s,int e,vector<int>&arr){
        if(s>e){
            return NULL;
        }

        int m=(s+e)/2;
        TreeNode* r1=new TreeNode(arr[m]);
        r1->left=buildBST(s,m-1,arr);
        r1->right=buildBST(m+1,e,arr);
        return r1;

    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        int s=0;
        int e=arr.size()-1;
        TreeNode* r1=buildBST(s,e,arr);
        return r1;
    }
};