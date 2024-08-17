class Solution {

private: 
void reverse(vector<int>& arr, int st,int end){
    while(st<end)
    {
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}
public:
    void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    if(k==0) return;

    // vector<int> temp;
    // int x=nums.size()-k;
    // if(nums.size()==1) return;

    // for(int i=x;i<nums.size();i++){
    //     temp.push_back(nums[i]);
    // }

    // for(int i=0;i<x;i++){
    //     temp.push_back(nums[i]);
    // }

    // nums=temp;

    int n=nums.size()-1;

    reverse(nums,0,n-k);
    reverse(nums,n-k+1,n);
    reverse(nums,0,n);
        
    }
};