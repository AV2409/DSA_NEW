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
    TreeNode* build(int l,int h,vector<int>& nums){
        if(l>h) return NULL;

        int mid=(l+h)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        if(l==h) return root;

        root->left=build(l,mid-1,nums);
        root->right=build(mid+1,h,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

        return build(0,n-1,nums);
    }
};