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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int l=left;
        int r=right;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(--l){
            prev=curr;
            curr=curr->next;
        }
        ListNode* headNode=curr;

        curr=head;
        while(--r){
            curr=curr->next;
        }
        ListNode* tailNode=curr;
        ListNode* next=curr->next;

        ListNode* revH=reverse(headNode,tailNode);
        headNode->next=next;
        if(!prev){
            head=revH;
        }
        else{
            prev->next=revH;
        }
        return head;

    }
};