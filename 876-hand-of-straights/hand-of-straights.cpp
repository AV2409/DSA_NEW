class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        while (!mp.empty()) {
            int ele = mp.begin()->first;
            int freq = mp.begin()->second;
            if (--freq == 0) {
                mp.erase(ele);
            } else {
                mp[ele]--;
            }

            for (int i = 1; i < groupSize; i++) {
                int next = ele + i;
                if (mp.find(next) == mp.end()) {
                    return false;
                }
                if (--mp[next] == 0)
                    mp.erase(next);
            }
        }

        return true;
    }
};