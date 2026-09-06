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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        while(curr){
            TreeNode* left=curr->left;
            
            if(!left){
                ans.push_back(curr->val);
                curr=curr->right;
                continue;
            }

            //find right most guy
            TreeNode* prev=NULL;
            TreeNode* temp=left;
            while(temp && temp!=curr){
                prev=temp;
                temp=temp->right;
            }

            if(!temp){
                ans.push_back(curr->val);
                prev->right=curr;
                curr=curr->left;
            }
            else if(temp==curr){
                
                prev->right=NULL;
                curr=curr->right;
            }
        }
        return ans;
    }
};