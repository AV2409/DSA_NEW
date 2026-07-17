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
    vector<int>trav;
    unordered_map<int,TreeNode*>mp;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->right);
        trav.push_back(root->val);
        mp[root->val]=root;
        inorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        // for(int x:trav){
        //     cout<<x<<" ";
        // }
        int n=trav.size();
        vector<int>preSum(n);
        preSum[0]=trav[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+trav[i];
        }

        for(int i=0;i<n;i++){
            int val=trav[i];
            TreeNode* node=mp[val];
            node->val=preSum[i];
        }
        return root;
    }
};