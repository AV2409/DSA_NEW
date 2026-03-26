class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = 0;

        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            int op1=arr[i];
            int op2=nodelete+arr[i];
            int op3=nodelete;//power used
            int op4=onedelete+arr[i];//power used


            nodelete = max(op1,op2);
            onedelete = max(op3, op4);

            ans = max({ans, nodelete, onedelete});
        }
        return ans;
    }
};