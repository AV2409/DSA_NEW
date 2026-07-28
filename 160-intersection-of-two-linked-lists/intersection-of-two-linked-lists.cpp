/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ca=headA;
        ListNode* cb=headB;
        bool swA=false;
        bool swB=false;
        while(true){
            if(ca==cb) return ca;
            ca=ca->next;
            cb=cb->next;
            if(ca==NULL &&!swA) 
            {
                ca=headB;
                swA=true;
            }
            if(cb==NULL &&!swB) {
                cb=headA;
                swB=true;
            }
            if(!ca && !cb) return NULL;
        }
        return ca;
    }
};