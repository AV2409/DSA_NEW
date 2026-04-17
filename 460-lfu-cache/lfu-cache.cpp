class LFUCache {
public:
    struct Node {
        int key, val, freq;
        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
        }
    };
    int cap, minFreq;
    unordered_map<int, list<Node*>::iterator> mp;
    map<int, list<Node*>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int f=node->freq;
        freq[f].erase(mp[node->key]);
        if(freq[f].empty()) freq.erase(f);
        f++;
        node->freq++;
        freq[f].push_front(node);
        mp[node->key]=freq[f].begin();

    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = *(mp[key]);
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cap==0) return;

        if(mp.find(key)!=mp.end()){
            Node* node = *(mp[key]);
            node->val = value;
            updateFreq(node);
            return;
        }

        if (mp.size() == cap) {
            int mini=freq.begin()->first;
            Node* node = freq[mini].back();
            mp.erase(node->key);
            freq[mini].pop_back();

            if (freq[mini].empty()) {
                freq.erase(mini);
            }
        }

        Node* newNode = new Node(key, value);
        freq[1].push_front(newNode);
        mp[key] = freq[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */