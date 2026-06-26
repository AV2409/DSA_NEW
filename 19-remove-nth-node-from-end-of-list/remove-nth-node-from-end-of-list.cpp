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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        ListNode* curr = head;
        if (fast == NULL) {
            ListNode* del = head;
            head = head->next;
            del->next = NULL;
            delete (del);
            return head;
        }

        while (fast->next) {
            fast = fast->next;
            curr = curr->next;
        }

        ListNode* del = curr->next;
        curr->next = del->next;
        del->next = NULL;
        delete (del);
        return head;

    }
};