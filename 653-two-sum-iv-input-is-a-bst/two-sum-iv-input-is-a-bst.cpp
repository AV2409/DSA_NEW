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
public:
    stack<TreeNode*>st;
    stack<TreeNode*>st2;
    BSTIterator(TreeNode* root) {
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        temp=root;
        while(temp){
            st2.push(temp);
            temp=temp->right;
        }
    }
    
    int nextGreater() {
        TreeNode* node=st.top();
        st.pop();
        TreeNode* temp=node->right;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        return node->val;
    }
    
    bool hasNextGreater() {
        return !st.empty();
    }

    int nextSmaller() {
        TreeNode* node=st2.top();
        st2.pop();
        TreeNode* temp=node->left;
        while(temp){
            st2.push(temp);
            temp=temp->right;
        }
        return node->val;
    }
    
    bool hasNextSmaller() {
        return !st2.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator *bst=new BSTIterator(root);
        int low=bst->nextGreater();
        int high=bst->nextSmaller();
        while(true){
            if(low>=high) return false;
            if(low+high==k) return true;
            else if(low+high<k){
                low=bst->nextGreater();
            }
            else {
                high=bst->nextSmaller();
            }
        }
        return false;
    }
};