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
        Node* temp=head;
        unordered_map<Node*,Node*>mp;
        while(temp){
            Node* newn=new Node(temp->val);
            mp[temp]=newn;
            temp=temp->next;
        }

        Node* curr=head;
        while(curr){
            Node* next=curr->next;
            Node* random=curr->random;

            Node* node=mp[curr];
            if(next) node->next=mp[next];
            if(random) node->random=mp[random];
            curr=curr->next;
        }
        return mp[head];
    }
};