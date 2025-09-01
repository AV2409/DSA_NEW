class Solution {
public:

    bool isPossible(int mid,vector<int>& weights, int days){
        int d=1;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>mid){
                d++;
                sum=weights[i];
            }
            if(d>days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0LL);
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, weights,days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};