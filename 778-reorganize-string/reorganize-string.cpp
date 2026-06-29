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
        if (n == 2 && mp.size() == 1)
            return "";

        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            int cnt = it.second;
            char ch = it.first;
            pq.push({cnt, ch});
        }

        while (!pq.empty()) {
            auto [cnt1,ch1]=pq.top();
            pq.pop();
            if(!ans.empty() && ans.back()==ch1) return "";
            ans+=ch1;
            cnt1--;
            if(cnt1==0) continue;

            if(!pq.empty()){
                auto [cnt2,ch2]=pq.top();
                pq.pop();
                ans+=ch2;
                cnt2--;
                if(cnt2) pq.push({cnt2,ch2});
            }
            else return "";
            if(cnt1) pq.push({cnt1,ch1});
        }

        return ans;
    }
};