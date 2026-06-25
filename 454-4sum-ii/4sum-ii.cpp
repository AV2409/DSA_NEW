class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<long long, long long> mp1;
        unordered_map<long long, long long> mp2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp1[nums1[i] + nums2[j]]++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans+=mp1[-(nums3[i] + nums4[j])];
            }
        }

        

        // for (auto it1 : mp1) {
        //     int s1 = it1.first;
        //     int cnt1 = it1.second;
        //     if (mp2.count(-s1))
        //         ans += cnt1 * mp2[-s1];
        // }
        return ans;
    }
};