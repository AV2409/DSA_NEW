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
    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
        ListNode* retTail=start;
        ListNode* retHead=end;
        ListNode* temp=start;
        ListNode* prev=NULL;
        ListNode* stop = end->next;
        while(temp!=stop){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return {retHead,retTail};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return head;

        ListNode* start = head;
        ListNode* end = head;
        int cnt = k;
        while (--cnt && end) {
            end = end->next;
        }
        if (!end)
            return head;

        ListNode* nextGroup = end->next;
        auto p = reverse(start, end);
        ListNode* newHead = p.first;
        ListNode* newTail = p.second;
        newTail->next = reverseKGroup(nextGroup, k);
        return newHead;
    }
};