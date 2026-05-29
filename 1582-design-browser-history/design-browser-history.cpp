class Node{
    public:
    string data;
    Node* next;
    Node* prev;

    Node(string _data){
        data=_data;
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory {
public:
    Node* head;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
    }
    
    void visit(string url) {
        Node* nn=new Node(url);
        nn->next=head;
        head->prev=nn;
        head=nn;
    }
    
    string back(int steps) {
        int x=steps;
        while(x--){
            if(head->next) head=head->next;
        }
        return head->data;
    }
    
    string forward(int steps) {
        int x=steps;
        while(x--){
            if(head->prev) head=head->prev;
        }
        return head->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */