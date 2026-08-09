class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string> st;
        int n=s.size();
        int i=0;

        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                string nn="";
                while(i<n && s[i]>='0' && s[i]<='9'){
                    nn+=s[i];
                    i++;
                }
                int nnint=stoi(nn);
                nums.push(nnint);
            }
            else if(s[i]=='['){
                st.push("[");
                i++;
            }

            else if(s[i]>='a' && s[i]<='z'){
                st.push(string(1, s[i]));
                i++;
            }
            else if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!="["){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string toAdd="";
                int times=nums.top();
                nums.pop();
                for(int x=0;x<times;x++){
                    toAdd+=temp;
                }
                st.push(toAdd);
                i++;
            }

        }
        vector<string>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        string ans="";
        for(string x:res){
            ans+=x;
        }
        return ans;
    }
};