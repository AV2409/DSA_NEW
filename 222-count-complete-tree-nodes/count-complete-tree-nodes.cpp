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
    int left(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    
    int right(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->right;
        }
        return cnt;
    }
    int ans=0;
    int helper(TreeNode* root){
        if(!root) return 0;
        int lh=left(root);
        int rh=right(root);

        if(lh==rh){
            return (1<<lh)-1;
        }
        else return helper(root->left)+helper(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        return helper(root);
    }
};