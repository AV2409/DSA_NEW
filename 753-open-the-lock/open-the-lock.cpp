class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st;
        st.insert(deadends.begin(), deadends.end());
        if(st.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        st.insert("0000");
        int steps = 0;
        while (!q.empty()) {
            int ss = q.size();
            for (int s = 0; s < ss; s++) {
                string code = q.front();
                q.pop();
                if (code == target)
                    return steps;
                for (int i = 0; i < 4; i++) {
                    string temp1 = code;
                    string temp2 = code;
                    //increment
                    if(temp1[i]=='9') temp1[i]='0';
                    else temp1[i]++;
                    if(!st.count(temp1)){
                        st.insert(temp1);
                        q.push(temp1);
                    }
                    //decrement
                    if(temp2[i]=='0') temp2[i]='9';
                    else temp2[i]--;
                    if(!st.count(temp2)){
                        st.insert(temp2);
                        q.push(temp2);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};