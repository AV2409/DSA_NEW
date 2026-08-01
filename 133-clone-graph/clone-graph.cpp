/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*>mp;
        unordered_map<int,bool>vis;
        queue<Node*>q;
        q.push(node);
        vis[node->val]=1;
        vector<Node*>trav;
        while(!q.empty()){
            Node* nn=q.front();
            q.pop();
            trav.push_back(nn);

            int val=nn->val;
            Node* clone=new Node(val);
            mp[nn]=clone;

            for(auto nei:nn->neighbors){
                if(!vis[nei->val]){
                    q.push(nei);
                    vis[nei->val]=1;
                }
            }
        }

        for(Node* nn:trav){
            Node* clone=mp[nn];
            for(auto nei:nn->neighbors){
                clone->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];


    }
};