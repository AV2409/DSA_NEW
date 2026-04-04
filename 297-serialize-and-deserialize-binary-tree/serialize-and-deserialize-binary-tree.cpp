/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "n";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "n,";
                continue;
            }

            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="n") return NULL;
        vector<string>vals;
        string temp="";
        for(char c:data){
            if(c==','){
                vals.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(vals[i]!="n"){
                node->left=new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;
            if(vals[i]!="n"){
                node->right=new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));