class Solution {
public:
    bool isPossible(int m,int n, int ans, int k) {
        int j = n - 1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && (i + 1) * (j + 1) > ans) {
                j--;
            }
            cnt += j + 1;
            if (cnt >= k)
                return true;
        }
        return false;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int h = m * n;
        int mid;
        int ans;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (isPossible(m, n, mid, k)) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};