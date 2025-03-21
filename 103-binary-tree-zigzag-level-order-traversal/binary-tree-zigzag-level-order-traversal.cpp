/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int l=1;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if(l%2==0){
                int x=level.size()-1;
                int y=0;
                while(y<x){
                    swap(level[y++],level[x--]);
                }
            }
            ans.push_back(level);
            l++;
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans=levelOrder(root);
        return ans;
    }
};