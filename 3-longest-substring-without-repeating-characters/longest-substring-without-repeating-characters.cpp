class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int l=0;
        int n=s.size();
        int ans=0;
        int duplicates=0;
        for(int r=0;r<n;r++){
            //add r
            hash[s[r]]++;
            if(hash[s[r]]>1) duplicates++;

            while(duplicates>0){
                hash[s[l]]--;
                if(hash[s[l]]==1) duplicates--;
                l++;
            }
            // update len
            ans=max(ans,r-l+1);
        }
        return ans;

    }
};