class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        vector<int>hash(256);
        int ans=0;
        while(r<n){
            hash[s[r]]++;
            while(hash[s[r]]>1){
                hash[s[l]]--;
                l++;
            }
            int len=r-l+1;
            ans=max(ans,len);
            r++;
        }
        return ans;
    }
};