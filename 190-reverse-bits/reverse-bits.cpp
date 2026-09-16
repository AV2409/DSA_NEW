class Solution {
public:
    int reverseBits(int n) {
       int ans=0;
       for(int i=0;i<32;i++){
        ans<<=1;
        int dig=n&1;
        ans|=dig;
        n>>=1;
       } 
       return ans;
    }
};