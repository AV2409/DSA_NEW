class Solution {
public:
    bool isPossible(int mid,vector<int>& weights, int days){
        int d=1;
        int w=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]+w>mid){
                w=weights[i];
                d++;
            }
            else w+=weights[i];
            if(d>days) return false;
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());;
        int h=accumulate(weights.begin(),weights.end(),0);;

        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(mid,weights,days)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};