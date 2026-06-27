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
        ListNode* prev=NULL;
        ListNode* curr=left;
        ListNode* next=NULL;
        ListNode* stop=right->next;

        while(curr!=stop){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
    ListNode* findR(ListNode* st,int k){
        k--;
        ListNode* temp=st;
        while(k-- && temp){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1||!head||!head->next) return head;

        ListNode* l=head;
        ListNode* r=findR(l,k);
        ListNode* before=NULL;
        ListNode* after=NULL;
        ListNode* start=NULL;
        ListNode* newH=NULL;

        while(l && r){
            after=r->next;
            start=l;
            ListNode* revH=reverse(l,r);
            if(before) before->next=revH;
            else newH=revH;
            before=start;
            start->next=after;
            l=after;
            r=findR(l,k);
        }
        return newH;
    }
};