class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        string ans = "";
        vector<int> hash(26, 0);
        for (char c : s) {
            hash[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if(hash[i]>0)
                pq.push({hash[i], i + 'a'});
        }

        while (!pq.empty()) {
            auto it1 = pq.top();
            pq.pop();
            int cnt1 = it1.first;
            char ch1 = it1.second;

            ans += ch1;
            cnt1--;
            if (cnt1 > 0) {
                if (pq.empty())
                    return "";
                auto it2 = pq.top();
                pq.pop();
                int cnt2 = it2.first;
                char ch2 = it2.second;

                ans += ch2;
                cnt2--;
                if(cnt2>0) pq.push({cnt2,ch2});
                pq.push({cnt1,ch1});
            }
        }
        return ans;
    }
};