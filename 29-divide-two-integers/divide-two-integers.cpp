class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=false; //positive
        if(divisor==1){
            return dividend;
        }
        if(dividend<0) sign=!sign;
        if(divisor<0) sign=!sign;
        long long n=abs(0LL+dividend);
        long long d=abs(0LL+divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;
            ans+=1LL<<cnt;
            n-=d<<cnt;
        }
        if(sign && ans>=INT_MAX) return INT_MIN+1;
        if(!sign && ans>=INT_MAX) return INT_MAX;
        if(sign) return -ans;
        return ans;
    }
};