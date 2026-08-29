class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();

        if(n2>n1) return -1;
        if(n2==n1){
            if(haystack==needle) return 0;
            return -1;
        }

        for(int i=0;i<n1;i++){
            int p1=i;
            int p2=0;

            while(p1<n1 && p2<n2 && haystack[p1]==needle[p2]){
                p1++;
                p2++;
            }
            if(p2==n2) return i;
        }
        return -1;
    }
};