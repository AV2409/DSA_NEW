/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        while(temp){
            Node* x=new Node(temp->val);
            mp[temp]=x;
            temp=temp->next;
        }

        temp=head;
        while(temp){
            Node* node=mp[temp];
            Node* next=mp[temp->next];
            Node* random=mp[temp->random];

            node->next=next;
            node->random=random;
            temp=temp->next;
        }
        return mp[head];
    }
};