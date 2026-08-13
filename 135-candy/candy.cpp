class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;
        int ans = 1;

        while (i < n) {
            if(ratings[i]==ratings[i-1]){
                i++;
                ans++;
                continue;
            }
            int peak = 1;

            // Increasing
            while (i < n && ratings[i] > ratings[i - 1]) {
                i++;
                peak++;
                ans += peak;
            }

            int down = 1;
            // Decreasing
            while (i < n && ratings[i] < ratings[i - 1]) {
                ans += down;
                i++;
                down++;
            }
            ans += max(0, down - peak);
        }

        return ans;
    }
};