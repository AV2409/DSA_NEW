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
        TreeNode* curr=root;
        vector<int>ans;

        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
                continue;
            }
            //find left's rightmost child
            TreeNode* temp=curr->left;
            TreeNode* prev=curr;
            while(temp && temp!=curr){
                prev=temp;
                temp=temp->right;
            }
            //connection making or connection deletion
            //{prev is last and temp is either curr or null}

            if(temp==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else if(temp==curr){
                prev->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};