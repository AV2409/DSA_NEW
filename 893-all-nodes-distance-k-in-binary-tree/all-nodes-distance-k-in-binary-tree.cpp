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
        unordered_map<TreeNode*, bool> vis;

        par[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            vis[node]=false;

            if (node->left) {
                par[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                par[node->right] = node;
                q.push(node->right);
            }
        }

        queue<TreeNode*> qq;
        int dist = 0;
        qq.push(target);

        while (!qq.empty()) {
            if(dist==k) break;
            int ss = qq.size();
            while (ss--) {
                TreeNode* node = qq.front();
                qq.pop();
                vis[node] = true;
                if (node->left && !vis[node->left]) {
                    qq.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    qq.push(node->right);
                }

                if (par[node] && !vis[par[node]]) {
                    qq.push(par[node]);
                }
            }
            dist++;
        }
        vector<int>ans;
        while(!qq.empty()){
            ans.push_back(qq.front()->val);
            qq.pop();
        }
        return ans;
    }
};