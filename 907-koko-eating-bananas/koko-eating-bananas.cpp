class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        int cnt=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            cnt+=piles[i]/mid;
            if(piles[i]%mid) cnt++;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        int mid;

        while (l <= r) {
            mid = r-(r-l)/2;
            if (isPossible(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};