class Solution {
public:
    long long helper(long long num){
        long long ans=0;
        while(num>0){
            int dig=num%10;
            ans=ans*10+dig;
            num/=10;
            if(ans<INT_MIN||ans>INT_MAX) return 0;
        }
        return ans;
    }
    int reverse(int x) {
        long long temp=x;
        long long num=abs(temp);

        long long ans=helper(num);
        if(x<0) return -ans;
        return ans;
    }
};