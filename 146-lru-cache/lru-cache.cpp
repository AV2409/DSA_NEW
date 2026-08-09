class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail; // Dummy head & dummy tail

    void insertFront(Node* node) {
        Node* prev = head;
        Node* next = head->next;

        node->next = next;
        node->prev = prev;

        prev->next = node;
        next->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
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
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val=value;
            deleteNode(node);
            insertFront(node);
            return;
        }

        Node* node=new Node({key,value});
        if(mp.size()==cap){
            Node* lru=tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        insertFront(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */