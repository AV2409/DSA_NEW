class Solution {
public:
    double helper(double x, long long n){
        if(n==1) return x;
        if(n==0) return 1;

        double temp=helper(x,n/2);
        double ans=temp*temp;
        if(n&1) ans=ans*x;
        return ans;
    }
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(n==0) return 1;

        if(x==-1){
            if(n%2) return -1;
            return 1;
        }
        
        long long N=n;
        if(n<0) {
            N=abs(1LL*n);
            x=1/x;
        }
        return helper(x,N);

    }
};