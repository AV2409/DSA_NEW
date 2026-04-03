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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        unordered_map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            auto [node,lvl]=q.front();
            q.pop();

            mp[lvl]=node->val;
            if(node->left) q.push({node->left,lvl+1});
            if(node->right) q.push({node->right,lvl+1});
        }

        for(int i=0;i<mp.size();i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};