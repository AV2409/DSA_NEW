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
    TreeNode* build(int st,int end,vector<int>&nums){
        if(st>end) return NULL;
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);

        root->left=build(st,mid-1,nums);
        root->right=build(mid+1,end,nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=build(0,n-1,nums);
        return root;
    }
};