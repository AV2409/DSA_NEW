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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        //{hd,vd,set}
        map<int, map<int, vector<int>>> mp;

        while (!q.empty()) {
            auto [node, p] = q.front();
            q.pop();
            int hd = p.first;
            int v = p.second;
            mp[hd][v].push_back(node->val);
            if (node->left)
                q.push({node->left, {hd - 1, v + 1}});
            if (node->right)
                q.push({node->right, {hd + 1, v + 1}});
        }
        for (auto it : mp) {
            vector<int> temp;
            for (auto rows : it.second) {
                auto vec = rows.second;
                sort(vec.begin(), vec.end());
                for (int x : vec) {
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};