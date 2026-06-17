class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>st;
        int ans=0;
        for(char c:password){
            if(st.size()==66) break;
            if(st.count(c)) continue;
            if(c>='a' && c<='z'){
                ans+=1;
            }
            else if(c>='A' && c<='Z'){
                ans+=2;
            }
            else if(c>='0' && c<='9'){
                ans+=3;
            }
            else{
                ans+=5;
            }
            st.insert(c);

        }
        return ans;
    }
};