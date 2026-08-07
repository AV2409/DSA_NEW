class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v) {
        key=k;
        val=v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int cap;
    unordered_map<int, Node*> mp;
    void insertFront(Node* node) {
        node->next=head;
        if(head) head->prev=node;
        head=node;
        if(tail==nullptr) tail=node;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
        
        if(node==head) head=head->next;
        if(node==tail) tail=tail->prev;

        node->next=NULL;
        node->prev=NULL;
    }
    void deleteBack(){
        if(head==tail) {
            delete tail;
            head=nullptr;
            tail=nullptr;
            return;
        }

        Node* toDel=tail;
        tail=tail->prev;
        toDel->prev=nullptr;
        tail->next=nullptr;
        delete toDel;
    }
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            insertFront(node);
            return;
        }

        Node* node=new Node(key,value);

        if(mp.size()==cap){
            int last=tail->key;
            mp.erase(last);
            deleteBack();
        }
        mp[key]=node;
        insertFront(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */