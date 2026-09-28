class Solution {
public:
    int maxDepth(string s) {
        int op=0;
        int ans=-1;
        for (char c:s){
            if(c=='(') op++;
            if(c==')') op--;
            ans=max(ans,op);
        }
        return ans;
    }
};