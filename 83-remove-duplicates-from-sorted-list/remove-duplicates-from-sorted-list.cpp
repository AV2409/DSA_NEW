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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* u = head;

        while (u) {
            ListNode* temp = u->next;

            while (temp) {
                if (temp->val == u->val) {
                    ListNode* duplicate = temp;
                    temp = temp->next;
                    u->next = temp;
                    delete duplicate; // Free memory of the duplicate node
                }

                else {
                    temp = temp->next;
                }
            }
            u = u->next;
        }
        return head;
    }
};