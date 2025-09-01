class Solution {
public:
    bool isPossible(int mid,vector<int>& piles, int h){
        int n=piles.size();
        int hours=0;

        for(int i=0;i<n;i++){
            int temp=ceil(double(piles[i])/mid);
            hours=hours+temp;
            if(hours>h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=-1;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};