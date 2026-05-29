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
    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
        ListNode* retTail=start;
        ListNode* retHead=end;
        ListNode* temp=start;
        ListNode* prev=NULL;
        ListNode* stop = end->next;
        while(temp!=stop){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return {retHead,retTail};
    }

    int getLen(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int n=getLen(head);
        k=k%n;
        if(k==0) return head;
        int x=n-k;

        ListNode* st=head;
        ListNode* end=head;
        while(--x){
            end=end->next;
        }
        ListNode* nextst=end->next;
        ListNode* nextend=end->next;
        auto zz=reverse(st,end);

        while(--k){
            nextend=nextend->next;
        }
        auto zz2=reverse(nextst,nextend);

        ListNode* fh=zz.first;
        ListNode* ft=zz.second;

        ListNode* sh=zz2.first;
        ListNode* stt=zz2.second;

        ft->next=sh;

        auto res=reverse(fh,stt);
        return res.first;
    }
};