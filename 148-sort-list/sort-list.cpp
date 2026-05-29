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
    ListNode* sortedMerge(ListNode* head1, ListNode* head2) {
        // code here
        ListNode* t1=head1;
        ListNode* t2=head2;
        ListNode* res=new ListNode(-1);
        ListNode* temp=res;
        while(t1 && t2){
            if(t1->val>t2->val){
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
            else{
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
        }
        while(t1){
            temp->next=t1;
            t1=t1->next;
            temp=temp->next;
        }
        while(t2){
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
        }
        return res->next;
    }

    ListNode* middleNode(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* fast=head->next->next;
        ListNode* slow=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;

        ListNode* middle=middleNode(head);
        ListNode* fH=head;
        ListNode* sH=middle->next;
        middle->next=NULL;
        ListNode* x=sortList(fH);
        ListNode* y=sortList(sH);
        return sortedMerge(x,y);
    }
};