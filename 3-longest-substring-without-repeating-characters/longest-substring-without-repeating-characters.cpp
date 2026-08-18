class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256);

        int l=0;
        int n=s.size();
        int cnt=0;
        int ans=0;
        for(int r=0;r<n;r++){
            hash[s[r]]++;
            if(hash[s[r]]>1) cnt++;
            while(cnt>0){
                hash[s[l]]--;
                if(hash[s[l]]==1) cnt--;
                l++;
            }
            ans=max(ans,r-l+1); 
        }
        return ans;
    }
};