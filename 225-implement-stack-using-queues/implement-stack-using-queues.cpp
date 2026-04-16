class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int s=q1.size();
        for(int i=1;i<s;i++){
            int ele=q1.front();
            q1.pop();
            q1.push(ele);
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int ele=q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();

    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */