class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp = {
            {1,"I"},   {5,"V"},    {10,"X"},   {50,"L"}, {100,"C"},
            {500,"D"}, {1000,"M"}, {4, "IV"},   {9, "IX"}, {40, "XL"},
            {90, "XC"}, {400, "CD"}, {900, "CM"},
        };
        vector<int>arr={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans = "";
        while (num > 0) {
            auto lb=lower_bound(arr.begin(),arr.end(),num);
            if(lb==arr.end()){
                ans += mp[1000];
                num -= 1000;
            }
            else{
                int idx=lb-arr.begin();
                if(idx==0){
                    ans += mp[1];
                    num -= 1;
                }
                else if(arr[idx]==num){
                    int nn=arr[idx];
                    ans+=mp[nn];
                    num-=nn;
                }
                else{
                    idx--;
                    int nn=arr[idx];
                    ans+=mp[nn];
                    num-=nn;
                }
            }

            // if (num >= 1000) {
            //     ans += mp[1000];
            //     num -= 1000;
            // } else if (num >= 900) {
            //     ans += mp[900];
            //     num -= 900;
            // } else if (num >= 500) {
            //     ans += mp[500];
            //     num -= 500;
            // } else if (num >= 400) {
            //     ans += mp[400];
            //     num -= 400;
            // } else if (num >= 100) {
            //     ans += mp[100];
            //     num -= 100;
            // } else if (num >= 90) {
            //     ans += mp[90];
            //     num -= 90;
            // } else if (num >= 50) {
            //     ans += mp[50];
            //     num -= 50;
            // } else if (num >= 40) {
            //     ans += mp[40];
            //     num -= 40;
            // }else if (num >= 10) {
            //     ans += mp[10];
            //     num -= 10;
            // }else if (num >= 9) {
            //     ans += mp[9];
            //     num -= 9;
            // } else if (num >= 5) {
            //     ans += mp[5];
            //     num -= 5;
            // } else if (num >= 4) {
            //     ans += mp[4];
            //     num -= 4;
            // } else {
            //     ans += mp[1];
            //     num -= 1;
            // }
        }
        return ans;
    }
};