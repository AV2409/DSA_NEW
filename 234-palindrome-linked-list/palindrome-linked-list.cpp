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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* fast=head;
        ListNode* slow=head;
        fast=head->next->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* h1=reverseList(slow->next);
        while(h1){
            if(head->val!=h1->val) return false;
            head=head->next;
            h1=h1->next;
        }
        return true;
    }
};