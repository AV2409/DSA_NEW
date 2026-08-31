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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        vector<int>arr;
        int i=1;
        while(next){
            if(curr->val>prev->val && curr->val>next->val){
                arr.push_back(i);
            }
            if(curr->val<prev->val && curr->val<next->val){
                arr.push_back(i);
            }

            prev=curr;
            curr=next;
            next=next->next;
            i++;
        }

        int n=arr.size();
        if(n<2) return {-1,-1};

        int mini=INT_MAX;
        
        int maxi=arr[n-1]-arr[0];
        
        for(int i=0;i<n-1;i++){
            mini=min(mini,arr[i+1]-arr[i]);
        }
        return {mini,maxi};
        
    }
};