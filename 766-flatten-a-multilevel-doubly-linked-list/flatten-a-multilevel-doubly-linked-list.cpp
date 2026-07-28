/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* prev=NULL;
    void dfs(Node* node){
        if(!node) return;
        prev=node;
        Node* nextNode=node->next;
        Node* childNode=node->child;
        node->child=NULL;

        if(childNode){
            node->next=childNode;
            childNode->prev=node;
            dfs(childNode);
        }
        if(prev){
            prev->next=nextNode;
        }
        if(nextNode){
            nextNode->prev=prev;
            dfs(nextNode);
        }

    }
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};