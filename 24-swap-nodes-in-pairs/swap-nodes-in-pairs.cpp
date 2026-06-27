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
    ListNode* reverse(ListNode* left,ListNode* right){
        ListNode* prev=left;
        left->next=NULL;
        right->next=prev;
        return right;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next){
            return head;
        }

        ListNode* l=head;
        ListNode* r=l->next;
        ListNode* before=NULL;
        ListNode* after=NULL;
        ListNode* start=l;
        while(l && r){
            after=r->next;
            start=l;
            ListNode* revH=reverse(l,r);
            if(before) before->next=revH;
            else head=revH;
            start->next=after;
            before=start;
            l=after;
            if(l)
                r=l->next;
        }
        return head;
    }
};