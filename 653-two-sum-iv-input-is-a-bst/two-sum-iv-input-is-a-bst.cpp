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

class BSTIterator {
private: 
    void pushAll1(TreeNode* root){
        while(root){
            st1.push(root);
            root=root->left;
        }
    }

    void pushAll2(TreeNode* root){
        while(root){
            st2.push(root);
            root=root->right;
        }
    }
public:
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    BSTIterator(TreeNode* root) {
        pushAll1(root);
        pushAll2(root);
    }
    
    int nextL() {
        TreeNode* node=st1.top();
        st1.pop();
        pushAll1(node->right);
        return node->val;
    }
    int nextG() {
        TreeNode* node=st2.top();
        st2.pop();
        pushAll2(node->left);
        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);

        int i=it.nextL();
        int j=it.nextG();

        while(i<j){
            if(i+j==k) return true;

            if(i+j>k) j=it.nextG();
            else i=it.nextL();
        }
        return false;
    }
};