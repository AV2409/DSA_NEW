class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size();
        int n2=b.size();

        int i=0;
        int j=0;
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c=0;
        while(i<n1 && j<n2){
            int x=a[i]-'0';
            int y=b[j]-'0';

            int sum=x+y+c;
            char dig=(sum%2)+'0';
            c=sum/2;
            ans+=dig;
            i++;
            j++;
        }

        while(i<n1){
            int x=a[i]-'0';

            int sum=x+c;
            char dig=(sum%2)+'0';
            c=sum/2;
            ans+=dig;
            i++;
        }

        while(j<n2){
            int y=b[j]-'0';

            int sum=y+c;
            char dig=(sum%2)+'0';
            c=sum/2;
            ans+=dig;
            j++;
        }
        if(c) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};