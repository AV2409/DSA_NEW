class Solution {
public:
    bool isPossible(int mid,vector<int>& piles, int h){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours += ceil((double)piles[i] / mid);
            if(hours>h) return false;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int hi=*max_element(piles.begin(),piles.end());

        int ans=l;
        while(l<=hi){
            int mid=(l+hi)/2;
            if(isPossible(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};