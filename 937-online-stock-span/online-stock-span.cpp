class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int spann=1;
        while(!st.empty() && st.top().first<=price){
            spann+=st.top().second;
            st.pop();
        }
        st.push({price,spann});
        return spann;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */