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
                temp=arr[i];
            }
            else{
                temp=pod+arr[i];
            }
            onedelete = max(pnd, temp);

            ans = max({ans, nodelete, onedelete});
        }
        return ans;
    }
};