class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    void insertNode(Node* node) {
        Node* prev = head;
        Node* next = head->next;

        node->next = next;
        node->prev = head;
        prev->next = node;
        next->prev = node;
    }
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    Node* head;
    Node* tail;
    int cap;
    int n;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        n = 0;
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        Node* node = mp[key];

        deleteNode(node);
        insertNode(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val=value;
            deleteNode(node);
            insertNode(node);
            return;
        }

        if(cap==n){
            Node* lru=tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
            n--;
        }

        Node* node=new Node(key,value);
        mp[key]=node;
        insertNode(node);
        n++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */