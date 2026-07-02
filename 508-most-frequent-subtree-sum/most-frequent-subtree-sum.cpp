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
    int maxi=0;
    int helper(TreeNode* root){
        if(!root) return 0;

        int l=helper(root->left);
        int r=helper(root->right);
        int temp=root->val+l+r;
        mp[temp]++;
        maxi=max(maxi,mp[temp]);
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }  
};