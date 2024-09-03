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
    void insert_at_tail(ListNode*& head, int x) {
        if (head == NULL) {
            head = new ListNode(x);
            return;
        }

        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        ListNode* newnode = new ListNode(x);
        temp->next = newnode;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {


        ListNode* temp = head;
        map<int, int> mp;
        if (head == NULL)
            return head;
        while (temp) {
            if (mp.find(temp->val) == mp.end()) {
                mp.insert({temp->val, 1});
            }

            else {
                mp[temp->val]++;
            }
            temp = temp->next;
        }
        ListNode* head1 = NULL;
        for (auto it : mp) {
            if (it.second == 1) {
                insert_at_tail(head1, it.first);
            }

        }
        return head1;
    }
};