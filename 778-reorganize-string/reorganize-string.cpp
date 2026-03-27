class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n == 1)
            return s;
        string ans = "";
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        if (n == 2 && mp.size() == 2)
            return s;
        if (n == 2 && mp.size() == 1 || mp.size() == 1)
            return "";

        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            int cnt = it.second;
            char ch = it.first;
            pq.push({cnt, ch});
        }

        while (!pq.empty()) {
            auto t1 = pq.top();
            pq.pop();
            int cnt1 = t1.first;
            char ch1 = t1.second;

            if (ans.size() && ch1 == ans.back()) {
                if (pq.empty())
                    return "";
                auto t2 = pq.top();
                pq.pop();
                int cnt2 = t2.first;
                char ch2 = t2.second;
                ans += ch2;
                cnt2--;
                if (cnt2)
                    pq.push({cnt2, ch2});
            }

            else {
                ans += ch1;
                cnt1--;
            }

            if (cnt1)
                pq.push({cnt1, ch1});
        }

        return ans;
    }
};