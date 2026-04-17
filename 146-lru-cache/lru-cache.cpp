class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int val;

    Node(int k, int v) {
        this->key = k;
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node*& head, Node*& node) {
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    node->prev = head;
}

void delete_node(Node*& node) {
    Node* nn = node->next;
    Node* pp = node->prev;
    pp->next = nn;
    nn->prev = pp;
}

class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int cap = 0;
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        int vall = mp[key]->val;
        Node* node = mp[key];
        delete_node(node);
        insertAtHead(head, node);
        return vall;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;

            // remove
            delete_node(node);
            insertAtHead(head, node);
            return;
        }

        else if (mp.size() < cap) {
            Node* node = new Node(key, value);
            insertAtHead(head, node);
            mp[key] = node;
            return;

        } else if (mp.size() >= cap) {
            Node* toDel = tail->prev;
            delete_node(toDel);
            mp.erase(toDel->key);
            delete toDel;
            Node* node = new Node(key, value);
            insertAtHead(head, node);
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