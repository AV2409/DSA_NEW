class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int z=n/8;
        int x=1;
        for(int i=1;i<=z;i++){
            ans+=8*x;
            x++;
        }
        z=n%8;
        ans+=z*x;
        return ans;
    }
};