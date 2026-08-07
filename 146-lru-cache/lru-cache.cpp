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
    Node *head, *tail;   // Dummy head & dummy tail

    void insertFront(Node* node){
        Node* prev=head;
        Node* next=head->next;

        node->next=next;
        node->prev=prev;
        
        head->next=node;
        next->prev=node;
    }

    void deleteNode(Node* node){
        Node* next=node->next;
        Node* prev=node->prev;

        next->prev=prev;
        prev->next=next;
    }

    
public:
    LRUCache(int capacity) {
        cap=capacity;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node=mp[key];
        
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

        if(mp.size()==cap){
            Node* lru=tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }
        Node* node=new Node(key,value);
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