class Solution {
public:
    string helper(string num,char ch){
        int c=0;
        int n2=ch-'0';
        string ans="";

        int i=num.size()-1;
        while(i>=0){
            int n1=num[i]-'0';
            int tot=(n1*n2)+c;
            c=tot/10;
            int dig=tot%10;
            ans+=to_string(dig);
            i--;
        }
        if(c) ans+=to_string(c);
        return ans;

    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int n1=num1.size();
        int n2=num2.size();

        if(n1<n2) return multiply(num2,num1);

        int j=n2-1;
        string toAdd="";
        vector<string>strs;
        int maxi=0;
        while(j>=0){
            string x=toAdd+helper(num1,num2[j]);
            cout<<x<<endl;
            strs.push_back(x);
            maxi=max(maxi,(int)x.length());
            j--;
            toAdd+='0';
        }
        int carry=0;
        string ans="";
        for(int i=0;i<maxi;i++){
            int sum=carry;
            for(string s:strs){
                if(i<s.size()){
                    sum+=s[i]-'0';
                }
            }
            int dig=sum%10;
            carry=sum/10;
            ans+=(dig+'0');
        }
        if(carry) ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        cout<<endl<<ans<<endl;
        return ans;
    }
};