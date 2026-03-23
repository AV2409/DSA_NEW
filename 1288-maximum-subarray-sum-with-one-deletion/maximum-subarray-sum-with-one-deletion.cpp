class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = -1e9;

        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int pnd = nodelete;
            int pod = onedelete;

            nodelete = max(nodelete + arr[i], arr[i]);
            int temp;
            if(pod==-1e9) {
                pod=arr[i];
            }
            else{
                pod=pod+arr[i];
            }
            onedelete = max(pnd, pod);

            ans = max({ans, nodelete, onedelete});
        }
        return ans;
    }
};