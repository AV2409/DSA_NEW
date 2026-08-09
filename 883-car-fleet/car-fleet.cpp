class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> arr;
        int n = speed.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        double lastTime = 0;
        for (int i = n-1; i >=0; i--) {
            double time = (double)(target - arr[i][0]) / arr[i][1];

            if (time > lastTime) {
                ans++;
                lastTime = time;
            }
        }

        return ans;
    }
};