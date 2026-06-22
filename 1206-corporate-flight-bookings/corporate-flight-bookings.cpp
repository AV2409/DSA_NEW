class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(auto books:bookings){
            int f=books[0];
            int l=books[1];
            int s=books[2];

            ans[f-1]+=s;
            if(l<n) ans[l]-=s;
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};