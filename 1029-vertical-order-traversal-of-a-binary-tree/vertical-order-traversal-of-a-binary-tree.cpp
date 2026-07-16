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

        queue<tuple<int,int,TreeNode*>>q;
        //{row,col,node}

        q.push({0,0,root});
        while(!q.empty()){
            auto [row,col,node]=q.front();
            q.pop();

            mp[col][row].insert(node->val);
            if(node->left) q.push({row+1,col-1,node->left});
            if(node->right) q.push({row+1,col+1,node->right});
        }

        vector<vector<int>>ans;

        for(auto cols:mp){
            vector<int>temp;
            for(auto it:cols.second){
                for(int x:it.second){
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};