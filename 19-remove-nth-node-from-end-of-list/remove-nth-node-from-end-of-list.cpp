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
    int getLen(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=getLen(head)-n+1;
        if(x==1){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete(temp);
            return head;
        }
        ListNode* temp=head;
        for(int i=1;i<x-1;i++) temp=temp->next;

        ListNode* toDel=temp->next;
        temp->next=toDel->next;
        toDel->next=NULL;
        delete(toDel);
        return head;
    }
};