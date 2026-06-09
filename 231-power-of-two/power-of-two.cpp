class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n=abs(n);
        int cnt=0;
        bool flag=false;
        while(n>0){
            if(n&1) cnt++;
            if(cnt>1) return false;
            n>>=1;
        }
        return cnt==1;
    }
};