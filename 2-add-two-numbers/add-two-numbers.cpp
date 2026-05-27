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
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    void insertAtHead(ListNode* &head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        int carry = 0;
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            int dig = x % 10;
            insertAtHead(res, dig);
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int x = l1->val + carry;
            carry = x / 10;
            int dig = x % 10;
            insertAtHead(res, dig);
            l1=l1->next;
        }

        while(l2){
            int x = l2->val + carry;
            carry = x / 10;
            int dig = x % 10;
            insertAtHead(res, dig);
            l2=l2->next;
        }

        if(carry) insertAtHead(res, carry);

        res=reverse(res);
        return res;
    }
};