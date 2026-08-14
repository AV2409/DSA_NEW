class Solution {
public:
    int solve(long long x){
        long long ans=0;
        while(x){
            int dig=x%10;
            ans=ans*10+dig;
            x=x/10;
            if(ans<INT_MIN||ans>INT_MAX) return 0;
        }
        return ans;
    }
    int reverse(int x) {
        long long num=1LL*x;
        return solve(num);
    }
};