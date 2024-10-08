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
    // Function to check if there are at least k nodes left in the list
    bool isPossible(ListNode* head, int k){
    int i=1;
    ListNode* temp=head;
    while(temp){
        if(i==k) return true;
        i++;
        temp=temp->next;
    }
    return false;
}

    bool getlength(ListNode* head, int k) {
        int c = 1;
        while (head != NULL) {
            if(c==k) return true;
            c++;
            head = head->next;
        }
        return false;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    // Function to reverse k nodes
        // Write your code here.
        // base case
        if (head == NULL) {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* curent = head;
        ListNode* forward = NULL;

        int c = 0;
        while (curent != NULL && c < k ) {
            forward = curent->next;

            curent->next = prev;
            prev = curent;
            curent = forward;
            c++;
        }

        //
        if (forward != NULL) {
            // head->next=kreverse(forwars,k);
            if (getlength(forward, k)) {
                head->next = reverseKGroup(forward, k);

            } else {
                head->next = forward;
            }
        }

        return prev;
    }
};
