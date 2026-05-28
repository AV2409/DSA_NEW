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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;

        ListNode* fast=head->next->next;
        ListNode* slow=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* toDel=slow->next;
        slow->next=toDel->next;
        toDel->next=NULL;
        delete(toDel);
        return head;
    }
};