class StockSpanner {
public:
    stack<pair<int,int>> st;
    int pge;
    int idx;
    StockSpanner() {
        pge=-1;
        idx=0;
    }

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (st.empty())
            pge = -1;
        else
            pge = st.top().second;
        
        int spann = idx - pge;
        st.push({price, idx});
        idx++;
        return spann;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */