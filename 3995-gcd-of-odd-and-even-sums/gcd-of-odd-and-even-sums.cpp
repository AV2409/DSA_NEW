class Solution {
public:
    int gcd(int x,int y){
        int gcd=1;
        if(x==y) return x;
        if(x%y==0) return y;
        if(y%x==0) return x;
        for(int i=2;i<=min(x,y);i++){
            if(x%i==0 && y%i==0) gcd=i;
        }
        return gcd;
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int N=2*n;
        int evenSum=(N*(N+1))/2-oddSum;
        cout<<oddSum;
        cout<<evenSum;
        return gcd(oddSum,evenSum);
    }
};