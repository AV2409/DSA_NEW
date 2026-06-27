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
        if (!head)
            return head;
        Node* curr = head;
        while (curr) {
            int val = curr->val;
            Node* next = curr->next;

            Node* dummy = new Node(val);
            curr->next = dummy;
            dummy->next = next;

            curr = next;
        }

        curr = head;
        Node* copyH = curr->next;
        curr = head;

        while (curr) {
            Node* copyNode = curr->next;
            Node* random = curr->random;
            if (random)
                copyNode->random = random->next;

            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            Node* copyNode = curr->next;
            curr->next = curr->next->next;
            Node* next = curr->next;
            if (next)
                copyNode->next = next->next;

            curr = curr->next;
        }
        return copyH;
    }
};