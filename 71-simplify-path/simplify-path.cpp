class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        int i = 0;
        while (i < n && path[i] == '/') {
                i++;
        }
        while (i < n) {
            
            string str = "";
            while (i < n && path[i] != '/') {
                str += path[i];
                i++;
            }
            while (i < n && path[i] == '/') {
                i++;
            }
            
            if (str == ".") {
                continue;
            } else if (str == "..") {
                if (!st.empty()) {
                    st.pop();
                }
                continue;
            } else {
                st.push(str);
            }
        }
        if (st.empty())
            return "/";
        vector<string> res;
        while (!st.empty()) {
            res.push_back("/" + st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        string ans = "";
        for (string x : res)
            ans += x;
        return ans;
    }
};