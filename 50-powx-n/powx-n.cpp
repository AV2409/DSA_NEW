class Solution {
public:
    double pow(double x, long long n){
        if(n==0) return 1;
        if(n==1) return x;

        double temp=pow(x,n/2);
        double ans=temp*temp;

        if(n%2) ans=ans*x;
        return ans;
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;
        if(x==-1){
            if(n%2) return -1;
            else return 1;
        }
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return pow(x,N);
    }
};