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
    ListNode* reverse(ListNode* st,ListNode* end){
        ListNode* curr=st;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* stop = end->next;
        while(curr!=stop){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(!head->next) return head;
        ListNode* before=NULL;
        ListNode* after=NULL;

        ListNode* temp=head;
        for(int i=1;i<left;i++){
            before=temp;
            temp=temp->next;
        }

        ListNode* st=temp;

        ListNode* x=temp;

        for(int i=left;i<right;i++){
            temp=temp->next;
        }
        ListNode* end=temp;
        after=temp->next;
        ListNode* revH=reverse(st,end);
        if(before) before->next=revH;

        x->next=after;
        if(before)
            return head;
        return revH;
        
    }
};