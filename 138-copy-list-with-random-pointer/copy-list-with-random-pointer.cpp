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



        Node* dNode = new Node(-1);
        Node* res=dNode;
        temp = head;
        //copy next links
        while (temp) {
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp = temp->next;
        }

        return dNode->next;
    }
};