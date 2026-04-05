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
    int minDepth(TreeNode* root) {
        int ans=0;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while (!q.empty()) {
            int x = q.size();
            for (int i = 0; i < x; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left==NULL && node->right==NULL) flag=true;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans++;
            if(flag) break;
        }
        return ans;
    }
};