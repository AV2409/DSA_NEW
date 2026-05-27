class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
    Node() { next = NULL; }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int len = 0;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    int get(int index) {
        if(index>=len) return -1;
        Node* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++;
            if (cnt == index + 1)
                return temp->data;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        len++;
        Node* newH = new Node(val);
        newH->next = head;
        head = newH;
        if (tail == NULL)
            tail = head;
    }

    void addAtTail(int val) {
        if (tail == NULL) {
            addAtHead(val);
            return;
        }
        len++;
        Node* newT = new Node(val);
        tail->next = newT;
        tail = newT;
    }

    void addAtIndex(int index, int val) {
        if (index == len) {
            addAtTail(val);
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index > len)
            return;
        
        len++;
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* toAdd = new Node(val);
        toAdd->next = temp->next;
        temp->next = toAdd;
    }

    void deleteAtHead() {
        Node* toDel = head;
        head = head->next;
        toDel->next = NULL;
        delete toDel;
        len--;
    }

    void deleteAtTail() {
        Node* temp=head;
        while(temp->next!=tail) temp=temp->next;

        Node* toDel = tail;
        tail = temp;
        delete toDel;
        len--;
    }

    void deleteAtIndex(int index) {
        if (index >= len)
            return;
        
        
        if (index == 0) {
            deleteAtHead();
            return;
        }

        if (index == len - 1) {
            deleteAtTail();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* toDel = temp->next;
        temp->next = toDel->next;
        toDel->next = NULL;
        delete toDel;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */