class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int maxi=0;
        vector<int>hash(26,0);
        int ans=0;
        for(int r=0;r<n;r++){
            hash[s[r]-'A']++;
            maxi=*max_element(hash.begin(),hash.end());
            while(r-l+1-maxi>k){
                hash[s[l]-'A']--;
                l++;
                maxi=*max_element(hash.begin(),hash.end());
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};