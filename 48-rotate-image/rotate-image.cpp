class Solution {
public:
    void rotate(vector<vector<int>>& arr) {

        // transpose
        int n=arr.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            while (j < n) {
                swap(arr[i][j], arr[j][i]);
                j++;
            }
        }

        // reverse rows

        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = n - 1;
            while (j < k) {
                swap(arr[i][j], arr[i][k]);
                j++;
                k--;
            }
        }
    }
};