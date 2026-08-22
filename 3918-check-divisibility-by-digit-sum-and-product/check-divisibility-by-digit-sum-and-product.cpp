class Solution {
public:
    int solve(int n){
        int prod=1;
        int sum=0;

        while(n>0){
            int dig=n%10;
            n=n/10;
            sum+=dig;
            prod*=dig;
        }

        return prod+sum;

    }
    bool checkDivisibility(int n) {
        int x=solve(n);
        if(n%x) return false;
        return true;
    }
};