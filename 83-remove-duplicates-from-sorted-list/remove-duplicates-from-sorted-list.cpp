/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void insert_at_tail(ListNode*& head, int x) {
        if (head == NULL) {
            head = new ListNode(x);
            return;
        }

        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        ListNode* newnode = new ListNode(x);
        temp->next = newnode;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head1 = NULL;

        ListNode* temp = head;
        if(head==NULL) return head;
        if (head1 == NULL) {
            insert_at_tail(head1, temp->val);
            temp = temp->next;
        }

        ListNode* temp1 = head1;

        while (temp) {
            if (temp1->val != temp->val) {
                insert_at_tail(head1, temp->val);
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
        return head1;
    }
};