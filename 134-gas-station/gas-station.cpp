class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>diff(n);

        for(int i=0;i<n;i++){
            diff[i]=gas[i]-cost[i];
        }

        int total=0;
        int curr=0;
        int st=0;
        for(int i=0;i<n;i++){
            total+=diff[i];
            curr+=diff[i];
            if(curr<0) {
                st=i+1;
                curr=0;
            }
        }
        if(st==n||total<0) return -1;
        return st;

    }
};