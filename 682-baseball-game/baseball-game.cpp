class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string s:operations){
            if(s=="+"){
                int x2=st.top();
                st.pop();
                int x1=st.top();
                st.pop();

                int res=x1+x2;
                st.push(x1);
                st.push(x2);
                st.push(res);
            }
            else if(s=="D"){
                int res=2*st.top();
                st.push(res);
            }
            else if(s=="C"){
                st.pop();
            }
            else{
                int x=stoi(s);
                st.push(x);
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};