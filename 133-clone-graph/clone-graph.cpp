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
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        set<Node*> vis;
        queue<Node*> q;
        q.push(node);
        vis.insert(node);

        while (!q.empty()) {
            Node* nn = q.front();
            q.pop();
            Node* newNode = new Node(nn->val);
            mp[nn] = newNode;
            for (Node* adj : nn->neighbors) {
                if (!vis.count(adj)) {
                    vis.insert(adj);
                    q.push(adj);
                }
            }
        }

        for(auto it:mp){
            Node* nn=it.first;
            Node* dummy=it.second;

            for(Node* adj:nn->neighbors){
                dummy->neighbors.push_back(mp[adj]);
            }
        }

        return mp[node];
    }
};