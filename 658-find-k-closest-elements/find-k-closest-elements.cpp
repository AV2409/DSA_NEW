class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;

        for (int num : arr) {
            int temp = abs(num - x);
            if (pq.size() == k) {
                if (pq.top().first > temp) {
                    pq.pop();
                    pq.push({abs(num - x), num});
                }
            } else
                pq.push({abs(num - x), num});
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};