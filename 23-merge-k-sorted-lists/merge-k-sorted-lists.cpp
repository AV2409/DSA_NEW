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
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        int n=lists.size();
        
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto list:lists){
            if(list) pq.push({list->val,list});
        }
        while(!pq.empty()){
            ListNode* x=pq.top().second;
            if(x->next) pq.push({x->next->val,x->next});
            temp->next=x;
            pq.pop();
            temp=temp->next;
        }

        return dummy->next;
    }
};