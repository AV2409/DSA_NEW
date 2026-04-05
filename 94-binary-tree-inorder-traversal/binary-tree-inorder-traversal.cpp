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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        vector<int>ans;
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);
            TreeNode* tt=node->right;
            while(tt){
                st.push(tt);
                tt=tt->left;
            }
        }
        return ans;

    }
};