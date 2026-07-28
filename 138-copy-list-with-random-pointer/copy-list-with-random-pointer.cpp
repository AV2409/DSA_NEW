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
        if(!head) return head;
        
        //interleaving
        Node* curr=head;
        while(curr){
            int v=curr->val;
            Node* copy=new Node(v);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        Node* newhead=head->next;

        //copy random pointers
        curr=head;
        while(curr){
            Node* random=curr->random;
            Node* copy=curr->next;

            if(random) copy->random=random->next;
            curr=curr->next->next;
        }
        

        //copy next pointers and restore list
        curr=head;
        while(curr){
            Node* nextNode=curr->next->next;
            Node* copy=curr->next;

            if(nextNode) copy->next=nextNode->next;
            curr->next=nextNode;
            curr=curr->next;
        }
        return newhead;
        
    }
};