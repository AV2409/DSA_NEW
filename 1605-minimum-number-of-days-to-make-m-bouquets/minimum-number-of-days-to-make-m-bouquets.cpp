class Solution {
public:

    bool isPossible(int mid,vector<int>& arr, int m, int k){
        int n=arr.size();
        int cnt=0;

        int i=0;
        while(i+k<=n){
            int valid=true;
            for(int j=0;j<k;j++){
                if(arr[i+j]>mid){
                    valid=false;
                    i+=j+1;
                    break;
                }
            }
            if(valid) {
                cnt++;
                i+=k;
            }
            if(cnt>=m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low=1;

        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(isPossible(mid,bloomDay,m,k)){
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