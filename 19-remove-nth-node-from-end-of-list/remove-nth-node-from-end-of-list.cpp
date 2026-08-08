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
    int getLen(ListNode* head) {
        int len = 0;

        while (head) {
            len++;
            head = head->next;
        }

        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getLen(head);
        int x=len-n;

        if(x==0){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* temp=head;

        while(--x){
            temp=temp->next;
        }
        ListNode* todel=temp->next;
        temp->next=todel->next;
        todel->next=NULL;
        delete todel;
        return head;

    }
};