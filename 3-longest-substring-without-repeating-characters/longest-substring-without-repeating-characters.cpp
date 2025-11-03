class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int n=s.size();
        int res=0;

        if(n==0) return 0;
        while(r<n){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
        
    }
};