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
        if (head == NULL)
            return NULL;
        // insertin in middle
        Node* temp = head;
        while (temp) {
            Node* x = new Node(temp->val);
            x->next = temp->next;
            temp->next = x;
            temp = temp->next->next;
        }

        // copy random links
        temp = head;
        while (temp) {
            Node* nextnn = temp->next->next;
            Node* node = temp->next;
            Node* random = temp->random;
            if (random)
                random = random->next;

            node->random = random;
            temp = nextnn;
        }

        Node* copyHead = head->next;
        temp = head;
        //copy next links
        while (temp) {
            Node* copy = temp->next;
            temp->next=copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            
            temp = temp->next;
        }

        return copyHead;
    }
};