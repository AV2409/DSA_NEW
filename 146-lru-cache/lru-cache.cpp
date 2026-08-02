class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        val = v;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {

public:
    Node* head = NULL;
    Node* tail = NULL;
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) { cap = capacity; }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = node->prev;
        }

        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;

        
        node->next = NULL;
        node->prev = NULL;
    }
    void insertFront(Node* node) {
        if (!head) {
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void deleteBack() {
        Node* toDel = tail;
        int k = toDel->key;
        mp.erase(k);
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        toDel->prev = NULL;
        delete toDel;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertFront(node);
        return node->val;
    }

    void put(int key, int value) {

        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertFront(node);
        } else {
            if (mp.size() == cap) {
                deleteBack();
            }
            Node* node = new Node(key, value);
            insertFront(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */