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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        

        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next=NULL;

        head2 = reverse(head2);
        int idx = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (head1 && head2) {
            if (idx % 2 == 0) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
            idx++;
        }
        while (head1) {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }

        while (head2) {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        head = dummy->next;
    }
};