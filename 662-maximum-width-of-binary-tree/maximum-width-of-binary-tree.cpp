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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long,TreeNode*>>q;
        q.push({0,root});
        long long ans=0;
        while(!q.empty()){
            long long ss=q.size();
            long long mini=q.front().first;
            long long maxi=-1;

            for(int i=0;i<ss;i++){
                long long idx=q.front().first;
                TreeNode* node=q.front().second;
                q.pop();
                idx-=mini;
                maxi=max(maxi,idx);

                if(node->left) q.push({2*idx+1,node->left});
                if(node->right) q.push({2*idx+2,node->right});
            }

            ans=max(ans,maxi+1);
        }
        return ans;
    }
};