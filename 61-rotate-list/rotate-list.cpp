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
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int n=getLen(head);
        k=k%n;
        if(k==0) return head;
        int x=n-k;

        ListNode* tail=head;
        while(tail->next) tail=tail->next;

        tail->next=head;
        
        ListNode* temp=head;
        while(--x) temp=temp->next;

        ListNode* newHead=temp->next;
        temp->next=NULL;
        return newHead;
    }
};