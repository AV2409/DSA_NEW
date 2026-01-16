class Solution {
public:
    int residuePrefixes(string s) {
        vector<bool>hash(26);
        int ans=0;
        int unq_cnt=0;
        for(int i=0;i<s.size();i++){
            if(!hash[s[i]-'a']){
                unq_cnt++;
                hash[s[i]-'a']=1;
            }
            if((i+1)%3==unq_cnt) ans++;;
        }
        return ans;
    }
};