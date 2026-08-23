class Node{
    public:
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=NULL;
    }
};

class MyCircularQueue {
    private:
    void addAtTail(int v){
        Node* nn=new Node(v);
        if(head==NULL){
            head=nn;
            tail=head;
        }
        else{
            tail->next=nn;
            tail=nn;
        }
    }
    void deleteAtHead(){
        Node* toDel=head;
        if(head==tail){
            delete toDel;
            head=NULL;
            tail=NULL;
            return;
        }

        head=head->next;
        delete toDel;

    }

public:
    int n;
    int cap;
    Node* head;
    Node* tail;
    MyCircularQueue(int k) {
        n=0;
        cap=k;
        head=NULL;
        tail=NULL;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        addAtTail(value);
        n++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        deleteAtHead();
        n--;
        return true;
    }
    
    int Front() {
        if(head) return head->val;
        return -1;
    }
    
    int Rear() {
        if(tail) return tail->val;
        return -1;
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */