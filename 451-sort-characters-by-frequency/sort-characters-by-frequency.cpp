class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        string ans = "";
        for (auto it : mp) {
            int cnt = it.second;
            char ch = it.first;
            pq.push({cnt,ch});
        }
        while(!pq.empty()){
            auto it=pq.top();
            int cnt = it.first;
            char ch = it.second;
            pq.pop();
            while (cnt--) {
                ans += ch;
            }
        }
        return ans;
    }
};