class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        if(n==2) return s+m;

        if(n%2) n--;
        n/=2;
        s=s+m;
        long long ans=1LL*s+1LL*(n-1)*(m-1);
        return ans;
    }
};