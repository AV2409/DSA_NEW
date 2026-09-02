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
        int slow=n;
        int fast=n;
        while(true){
            slow=fun(slow);
            fast=fun(fast);
            fast=fun(fast);

            if(slow==1) return true;
            if(fast==slow) return false;
        }
        return true;
    }
};