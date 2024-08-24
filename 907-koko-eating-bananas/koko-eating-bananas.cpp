bool ispossible(vector<int>& piles, int h,int mid){

        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours=hours+(piles[i]/mid);

            if(piles[i]%mid!=0) {
                hours++;
            }

            if(hours>h) return 0;
            
        }

        return 1;

    }

class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(),piles.end());

        int s=1;
        int e=piles[piles.size()-1];

        int mid=s+(e-s)/2;
        int k;

        while(s<=e){

        if(ispossible(piles,h,mid)){
            k=mid;
            e=mid-1;
        }

        else{
            s=mid+1;
        }

        mid=s+(e-s)/2;

        }
        return k;


        
    }
};