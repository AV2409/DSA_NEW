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
    TreeNode* find(TreeNode* root, int start) {
        if (!root)
            return NULL;
        if (root->val == start)
            return root;

        TreeNode* l = find(root->left, start);
        TreeNode* r = find(root->right, start);
        if (l)
            return l;
        return r;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* start_node = find(root, start);
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
        vis[start_node] = true;
        // traversal
        qq.push(start_node);
        int time = -1;
        while (!qq.empty()) {
            time++;
            int size = qq.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = qq.front();
                qq.pop();
                TreeNode* parent = par[node];
                TreeNode* l = node->left;
                TreeNode* r = node->right;

                // parent
                if (parent && !vis[parent]) {
                    qq.push(parent);
                    vis[parent] = true;
                }

                // left
                if (l && !vis[l]) {
                    qq.push(l);
                    vis[l] = true;
                }

                // right
                if (r && !vis[r]) {
                    qq.push(r);
                    vis[r] = true;
                }
            }
        }
        return time;
    }
};