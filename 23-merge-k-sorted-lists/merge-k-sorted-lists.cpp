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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(ListNode* head:lists){
            if(head) pq.push({head->val,head});
        }

        ListNode* res = new ListNode(-1);
        ListNode* tt = res;
        while (!pq.empty()) {
            ListNode* x = pq.top().second;
            pq.pop();
            tt->next = x;
            tt = tt->next;
            x = x->next;
            if (x)
                pq.push({x->val,x});
        }
        return res->next;
    }
};