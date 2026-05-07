class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>have(26);
        for(char ch: chars) have[ch-'a']++;
        int ans=0;
        for(string st:words){
            vector<int>needed=have;
            bool valid=true;
            for(char ch:st){
                if(needed[ch-'a']==0){
                    valid=false;
                    break;
                }
                needed[ch-'a']--;
                
            }
            if(valid) ans+=st.size();
        }
        return ans;
    }
};