class Solution {
public:
    int cnt=0;
    void merge(int st,int mid,int end,vector<int> &arr){
        vector<int>ans;
        int j=mid+1;
        int i=st;
        int x=i;
        int y=j;
        while(x<=mid){
            while(y<=end && (long long)arr[x] > 2LL * arr[y]) y++;
            cnt+=y-mid-1;
            x++;
        }
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else {
                ans.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        
        while(j<=end){
            ans.push_back(arr[j]);
            j++;
        }
        
        for(int k=st;k<=end;k++){
            arr[k]=ans[k-st];
        }
    }
    void mergeSort(int st,int end,vector<int> &arr){
        if(st>=end) return;
        
        int mid=(st+end)/2;
        
        mergeSort(st,mid,arr);
        mergeSort(mid+1,end,arr);
        merge(st,mid,end,arr);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return cnt;
    }
};