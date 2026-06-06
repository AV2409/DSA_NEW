class Solution {
public:
    int cnt=0;
    void merge(vector<int>&arr,int st,int mid,int end){
        int i=st;
        int j=mid+1;
        int y=mid+1;
        for(int x=st;x<=mid;x++){
            while(y<=end && arr[x]>2LL*arr[y]) y++;
            cnt+=y-mid-1;
        }
        vector<int>ans;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]) ans.push_back(arr[i++]);
            else {
                ans.push_back(arr[j++]); 
            }
        }
        
        while(i<=mid){
            ans.push_back(arr[i++]);
        }
        
        while(j<=end){
            ans.push_back(arr[j++]);
        }
        for (int k = 0; k < ans.size(); k++) {
            arr[st + k] = ans[k];
        }
    }
    void mergeSort(vector<int> &arr,int st,int end){
        if(st>=end) return;
        
        int mid=(st+end)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};