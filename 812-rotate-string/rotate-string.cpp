class Solution {
public:
    string rotate(string s,int k){
        reverse(s.begin(),s.begin()+k);
        reverse(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        int n=s.size();
        for(int i=1;i<n;i++){
            string ss=rotate(s,i);
            if(ss==goal) return true;
        }
        return false;
    }
};