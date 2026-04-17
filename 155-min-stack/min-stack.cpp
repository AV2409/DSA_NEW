class MinStack {
public:
    stack<long long> st;
    long long mini = 1e18;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini=val;
        }
        else if (val < mini) {
            st.push(2LL * val - mini);
            mini=val;
        } else
            st.push(val);
    }

    void pop() {
        long long ele = st.top();
        st.pop();
        if (ele < mini)
            mini = 2 * mini - ele;
    }

    int top() {
        long long ele = st.top();
        if (ele < mini) return mini;  // encoded case
        return ele;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */