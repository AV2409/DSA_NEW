class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int l=0;
        int n=s.size();
        int ans=0;
        for(int r=0;r<n;r++){
            //add r
            hash[s[r]-'A']++;
            int maxi=*max_element(hash.begin(),hash.end());
            int len=r-l+1;
            while(len-maxi>k){
                hash[s[l]-'A']--;
                l++;
                maxi=*max_element(hash.begin(),hash.end());
                len=r-l+1;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};