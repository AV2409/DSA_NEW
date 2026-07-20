class Solution {
public:
    int compress(vector<char>& chars) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        string ans;
        int n=chars.size();
        while(r<n){
            r=l;
            while(r<n && chars[l]==chars[r]) r++;
            int len=r-l;
            ans+=chars[l];
            if(len>1) ans+=to_string(len);
            l=r;
        }
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};