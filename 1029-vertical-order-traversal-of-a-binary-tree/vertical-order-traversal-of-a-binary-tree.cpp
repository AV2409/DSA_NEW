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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;

        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});

        while(!q.empty()){
            auto [node,hd,vd]=q.front();
            q.pop();
            mp[hd][vd].insert(node->val);
            if(node->left) q.push({node->left,hd-1,vd+1});
            if(node->right) q.push({node->right,hd+1,vd+1});
        }

        vector<vector<int>>ans;
        for(auto it1:mp){
            vector<int>temp;
            for(auto it2:it1.second){
                for(auto ele:it2.second) temp.push_back(ele);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};