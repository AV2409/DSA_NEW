class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        deque<char>st;

        for(char c:s){
            if(!st.empty()&&st.back()==c) st.pop_back();
            else st.push_back(c);
        }

        string ans="";
        while(!st.empty()){
            ans+=st.front();
            st.pop_front();
        }

        return ans;
    }
};