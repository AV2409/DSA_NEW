/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;

        queue<TreeNode*> q;
        par[root] = NULL;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                par[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                par[node->right] = node;
            }
        }

        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target]=true;
        vector<int> ans;
        int dist = 0;
        while (!q.empty()) {
            int ss = q.size();
            if (dist == k)
                break;

            for (int i = 0; i < ss; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(par[node] && !vis[par[node]]) {
                    q.push(par[node]);
                    vis[par[node]]=true;
                }
            }
            dist++;
        }
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};