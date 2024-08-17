class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int maxlen=0;
    int l=0;
    int r=1;
    int maxprofit=0;
    
    while(r<n){
        if(prices[l]>prices[r]) {
            l=r;
        }
        int profit=prices[r]-prices[l];
        maxprofit=max(profit,maxprofit);
        r++;
    }

    return maxprofit;
        
    }
};