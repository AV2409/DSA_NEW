class Solution {
public:

    bool isPossible(int mid,vector<int>& arr, int m, int k){
        int n=arr.size();
        int cnt=0;

        int flowers=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                flowers++;
                if(flowers==k) {
                    cnt++;
                    flowers=0;
                }

                if(cnt==m) return true;
            }
            else{
                flowers=0;
            }
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