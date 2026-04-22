class Node {
public:
    char data;
    Node* children[26];
    bool isTerminal;

    Node(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node('\0'); }

    void insert(string word) {
        int n = word.size();
        Node* temp = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            Node* child;
            if (temp->children[idx]) {
                child = temp->children[idx];
            } else {
                child = new Node(word[i]);
                temp->children[idx] = child;
            }
            temp = child;
        }
        temp->isTerminal = true;
    }

    bool search(string word) {
        int n = word.size();
        Node* temp = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';

            if (!temp->children[idx]) {
                return false;
            }
            temp = temp->children[idx];
        }
        return temp->isTerminal;
    }

    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* temp = root;
        for (int i = 0; i < n; i++) {
            int idx = prefix[i] - 'a';

            if (!temp->children[idx]) {
                return false;
            }
            temp = temp->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */