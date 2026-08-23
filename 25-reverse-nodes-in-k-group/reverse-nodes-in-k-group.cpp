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
    ListNode* findKNode(ListNode* head, int k){
        ListNode* curr=head;
        while(--k && curr){
            curr=curr->next;
        }
        return curr;
    }
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* prev=NULL;
        ListNode* target=tail->next;
        ListNode* curr=head;

        while(curr!=target){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* ansHead=head;

        ListNode* curr=head;
        while(curr){
            ListNode* h=curr;
            ListNode* t=findKNode(h,k);
            if(t==NULL) break;
            ListNode* next=t->next;
            ListNode* revH=reverse(h,t);
            h->next=next;
            if(prev){
                prev->next=revH;
            }
            else {
                ansHead=revH;
            }
            prev=h;
            curr=next;
        }
        return ansHead;
    }
};