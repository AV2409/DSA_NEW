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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        bool rev=false;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>temp(s);
            for(int i=0;i<s;i++){
                TreeNode* node= q.front();
                q.pop();
                if(rev) temp[s-i-1]=node->val;
                else temp[i]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            rev=!rev;
            ans.push_back(temp);
        }
        return ans;
    }
};