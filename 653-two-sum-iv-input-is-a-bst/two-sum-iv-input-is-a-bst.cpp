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
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;

    BSTIterator(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            st1.push(curr);
            curr=curr->left;
        }
        curr=root;
        while(curr){
            st2.push(curr);
            curr=curr->right;
        }
    }
    
    int nextGreater() {
        TreeNode* curr=st1.top();
        st1.pop();
        TreeNode* temp=curr->right;
        while(temp){
            st1.push(temp);
            temp=temp->left;
        }
        return curr->val;
    }

    int nextLesser() {
        TreeNode* curr=st2.top();
        st2.pop();
        TreeNode* temp=curr->left;
        while(temp){
            st2.push(temp);
            temp=temp->right;
        }
        return curr->val;
    }
    bool hasNextGreater() {
        return !st1.empty();
    }
    bool hasNextLesser() {
        return !st2.empty();
    }
    
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* bst=new BSTIterator(root);

        int l=bst->nextGreater();
        int r=bst->nextLesser();

        while(l<r){
            int sum=l+r;
            if(sum==k) return true;
            else if(sum<k) l=bst->nextGreater();
            else r=bst->nextLesser();
        }
        return false;
    }
};