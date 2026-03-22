class Solution {
public:

    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        int maxfreq;
        vector<int> hash(26);
        int n=s.size();
        for (int h = 0; h < n; h++) {
            hash[s[h]-'A']++;
            maxfreq=*max_element(hash.begin(),hash.end());
            while(h-l+1-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
                maxfreq=*max_element(hash.begin(),hash.end());
            }
            ans=max(ans,h-l+1);
        }
        return ans;
    }
};