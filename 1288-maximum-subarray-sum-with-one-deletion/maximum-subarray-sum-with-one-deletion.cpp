class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDel=arr[0];
        int oneDel=0;

        int ans=arr[0];
        int n=arr.size();

        for(int i=1;i<n;i++){
            int tempNoDel=noDel;
            int tempOneDel=oneDel;

            noDel=max(arr[i],arr[i]+tempNoDel);
            
            int delCurr=tempNoDel;
            int previouslyOneDel=arr[i]+tempOneDel;
            oneDel=max(delCurr,previouslyOneDel);
            ans=max({ans,noDel,oneDel});
        }
        return ans;
    }
};