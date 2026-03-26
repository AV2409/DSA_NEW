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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* temp=head;
        ListNode* temp1=NULL;
        for(int i=0;i<left-1;i++){
            temp1=temp;
            temp=temp->next;
        }

        ListNode*ogStart=temp;

        ListNode* prev=NULL;
        ListNode* curr=temp;
        ListNode* next=NULL;

        for(int i=left;i<=right;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ogStart->next=curr;
        if(temp1) temp1->next=prev;
        if(left==1) return prev;
        return head;

    }
};