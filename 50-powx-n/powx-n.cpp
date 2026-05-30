class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0)
            return 1;
        double tt = helper(x, n / 2);
        if (n % 2) {
            return x * tt * tt;
        }
        return tt * tt;
    }
    double myPow(double x, int n) {
        if(x==1||n==0) return 1;
        if(x==-1){
            if(n%2) return -1;
            else return 1;
        }
        long long pow=n;
        if(x==0) return 0;
        if (n < 0) {
            x = 1 / x;
            pow=-pow;
        }
        return helper(x, pow);
    }
};