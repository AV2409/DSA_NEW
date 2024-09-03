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
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head)
            return nullptr;
        ListNode* prev = NULL; // Previous node starts at dummy
        ListNode* curr = head; // Current node starts at head

        while (curr) {
            bool isDuplicate = false;

            // Check if current node is a duplicate
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
                isDuplicate = true;
            }

            // If duplicates were found, skip them
            if (isDuplicate) {
                if (prev == NULL) {
                    head = curr->next;
                } else
                    prev->next = curr->next;
            } else {
                if (prev == NULL) {
                    prev = head;
                } else

                    prev = prev->next;
            }

            curr = curr->next;
        }

        return head;
    }
};