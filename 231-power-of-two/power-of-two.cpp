class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;

        int s=0;
        int e=31;

        int mid=s+(e-s)/2;

        while(s<=e){
            if(pow(2,mid)==n) return true;

            if(pow(2,mid)<n) s=mid+1;

            else if(pow(2,mid)>n) e=mid-1;

            mid=s+(e-s)/2;
        }

        return false;

    }
};