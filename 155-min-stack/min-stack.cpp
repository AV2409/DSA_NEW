class MinStack {
public:
    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        int mini=value;
        if(!minSt.empty()) mini=min(mini,minSt.top());
        st.push(value);
        minSt.push(mini);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */