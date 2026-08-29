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
    struct CompareNode {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,CompareNode>pq;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;

        for(auto l:lists) {
            if(l) pq.push(l);
        }

        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();

            curr->next=node;
            node=node->next;
            if(node) pq.push(node);
            curr=curr->next;
        }
        return dummy->next;
    }
};