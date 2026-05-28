/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode *head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=getLen(headA);
        int m=getLen(headB);
        ListNode* a=headA;
        ListNode* b=headB;

        if(n>m){
            int x=n-m;
            while(x--) a=a->next;
        }
        if(m>n){
            int x=m-n;
            while(x--) b=b->next;
        }

        while(a && b){
            if(a==b) return a;
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};