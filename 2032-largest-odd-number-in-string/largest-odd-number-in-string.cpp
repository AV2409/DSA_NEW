class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size()-1;
        int idx=-1;
        for(int i=n;i>=0;i--){
            if((num[i]-'0')%2){
                idx=i;
                break;
            }
        }
        if(idx==-1) return "";
        else{
            return num.substr(0, idx+1);   
        }
    }
};