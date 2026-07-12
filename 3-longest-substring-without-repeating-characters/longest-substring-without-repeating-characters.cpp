class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int l=0;
        int r=0;
        int ans=0;
        int cnt=0;
        for(int r=0;r<s.size();r++){
            //include r
            hash[s[r]]++;
            if(hash[s[r]]>1) cnt++;

            while(cnt>0){
                if(hash[s[l]]==2) cnt--;
                hash[s[l]]--;
                l++;
            }

            ans=max(ans,r-l+1);
        }
        return ans;
    }
};