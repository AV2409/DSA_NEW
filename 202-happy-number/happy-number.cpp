class Solution {
public:
    int fun(int n) {
        int ans = 0;
        while (n > 0) {
            int dig = n % 10;
            ans += dig * dig;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int>st;
        while(n!=1){
            if(st.count(n)) return false;
            st.insert(n);
            n=fun(n);
        }
        return true;
    }
};