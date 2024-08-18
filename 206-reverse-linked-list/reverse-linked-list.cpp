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
private: 
// ListNode* reverse(ListNode* &head,ListNode* curr,ListNode* prev)
// {  
//     if(curr==NULL) return prev;

//     ListNode* next=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=next;
//     return reverse(next,curr,prev);

// }

void reverse1(ListNode* &head, ListNode* curr, ListNode* prev) {
    if (curr == nullptr) {
        head = prev; // Update the head pointer
        return;
    }

    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    head=prev;
    reverse1(head, curr, prev);
}
public:
    ListNode* reverseList(ListNode* head) 
    {
        /*
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next= NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        */
/*
        ListNode* curr = head;
        ListNode* prev = NULL;
        return reverse(head,curr,prev);
*/

        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse1(head,curr,prev);
        return head;
    }
};