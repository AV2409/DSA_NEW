class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string>st;
        int n=word.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=word[j];
                st.insert(temp);
            }
        }
        int cnt=0;
        for(string x:patterns){
            if(st.count(x)) cnt++;
        }
        return cnt;
    }
};