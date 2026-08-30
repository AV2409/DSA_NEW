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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode*h1=head;
        ListNode* h2=head->next;

        ListNode*c1=head;
        ListNode* c2=head->next;

        while(c1 && c2){
            ListNode* next1=c2->next;
            ListNode* next2=nullptr;
            if(next1) next2=next1->next;

            c1->next=next1;
            c2->next=next2;

            c1=next1;
            c2=next2;
        }
        c1=h1;
        c2=h2;
        while(c1->next){
            c1=c1->next;
        }
        c1->next=c2;
        return h1;

    }
};