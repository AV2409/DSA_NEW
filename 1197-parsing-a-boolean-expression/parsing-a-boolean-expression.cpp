class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>opr;
        stack<char>st;

        for(char ch:expression){
            if(ch=='&'||ch=='|'||ch=='!'){
                opr.push(ch);
            }
            if(ch=='('||ch=='t'||ch=='f'){
                st.push(ch);
            }
            if(ch==')'){
                char o=opr.top();
                opr.pop();

                if(o=='&'){
                    bool isF=false;
                    while(!st.empty()&&st.top()!='('){
                        if(st.top()=='f') isF=true;
                        st.pop();
                    }
                    st.pop();
                    if(isF) st.push('f');
                    else st.push('t');
                }
                if(o=='|'){
                    bool isT=false;
                    while(!st.empty()&&st.top()!='('){
                        if(st.top()=='t') isT=true;
                        st.pop();
                    }
                    st.pop();
                    if(isT) st.push('t');
                    else st.push('f');
                }
                if(o=='!'){
                    bool isT=false;
                    while(!st.empty()&&st.top()!='('){
                        if(st.top()=='t') isT=true;
                        st.pop();
                    }
                    st.pop();
                    if(isT) st.push('f');
                    else st.push('t');
                }
            }
        }
        if(st.top()=='f') return false;
        return true;
    }
};