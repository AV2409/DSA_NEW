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

        // parent map tyaar krna
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            vis[node] = false;
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

        vis[target] = 1;
        // traversal
        qq.push(target);
        int dist = 0;
        vector<int> ans;
        while (!qq.empty()) {
            int size = qq.size();
            if (dist > k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* node = qq.front();
                qq.pop();
                if (dist == k)
                    ans.push_back(node->val);

                TreeNode* parent = par[node];
                TreeNode* l = node->left;
                TreeNode* r = node->right;

                // parent
                if (parent && !vis[parent]) {
                    qq.push(parent);
                    vis[parent] = 1;
                }

                // left
                if (l && !vis[l]) {
                    qq.push(l);
                    vis[l] = 1;
                }

                // right
                if (r && !vis[r]) {
                    qq.push(r);
                    vis[r] = 1;
                }
            }
            dist++;
        }
        return ans;
    }
};