class Solution {
public:
    bool isValid(unordered_map<int, int>& mp) {
        if (mp.size() == 1)
            return true;

        set<int> cnts;
        for (auto it : mp) {
            cnts.insert(it.second);
            if (cnts.size() > 2)
                return false;
        }
        if (cnts.size() < 2)
            return false;
        auto it = cnts.begin();
        int first = *it;
        ++it;
        int sec = *it;

        return sec == 2 * first;
    }
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            map<int, int> cnts;
            for (int j = i; j < n; j++) {
                int oldFreq = mp[nums[j]];

                if (oldFreq > 0) {
                    cnts[oldFreq]--;
                    if (cnts[oldFreq] == 0)
                        cnts.erase(oldFreq);
                }
                mp[nums[j]]++;
                cnts[mp[nums[j]]]++;
                if (cnts.size() > 2)
                    continue;
                if (mp.size() == 1) {
                    ans = max(ans, j - i + 1);
                    continue;
                }
                if (mp.size() > 1 && cnts.size() < 2)
                    continue;

                auto it = cnts.begin();
                int first = it->first;
                ++it;
                int sec = it->first;
                if (sec == 2 * first)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};