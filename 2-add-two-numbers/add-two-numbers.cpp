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
    ListNode* head=NULL;
    ListNode* tail=NULL;
    void insert(int n){
        ListNode* newnode=new ListNode(n);
        if(!head) {
            head=newnode;
            tail=newnode;
            return;
        }
        tail->next=newnode;
        tail=tail->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int c=0;
        while(l1 || l2){
            int x=0;
            int y=0;
            if(l1) x=l1->val;
            if(l2) y=l2->val;
            int sum=c+x+y;
            int dig=sum%10;
            c=sum/10;
            insert(dig);
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(c) insert(c);
        return head;
    }
};