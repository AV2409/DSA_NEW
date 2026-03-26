class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double avg=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        avg=sum/k;
        int cnt=0;
        int n=arr.size();
        if(avg>=threshold) cnt++;
        int j=k;
        while(j<n){
            sum=sum+arr[j]-arr[j-k];
            avg=sum/k;
            if(avg>=threshold) cnt++;
            j++;
        }
        return cnt;
    }
};