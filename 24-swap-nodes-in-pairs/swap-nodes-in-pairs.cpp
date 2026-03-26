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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int times=2;
        while (times--&&curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp=head;
        ListNode* nextGroup=head->next->next; 
        ListNode* start=reverse(temp);
        ListNode* prevTail=start->next;
        // prevTail->next = nextGroup;
        temp=nextGroup;
        while(temp&&temp->next){
            ListNode* nextGroup=temp->next->next;  
            ListNode* newHead = reverse(temp);
            prevTail->next=newHead;
            prevTail = temp;
            // prevTail->next = nextGroup;
            temp=nextGroup;
        }

        prevTail->next=temp;

        return start;

    }
};