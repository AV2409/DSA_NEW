class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string x : words) {
            mp[x]++;
        }

        //{cnt,str}
        priority_queue<pair<int, string>> pq;

        for (auto it : mp) {
            string str = it.first;
            int cnt = -it.second;

            pq.push({cnt, str});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while (!pq.empty()) {
            string x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};