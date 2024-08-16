class Solution {

private:
    int find(vector<int>& arr, int req, int s,int e){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==req) return mid;
            else if(arr[mid]>req) e=mid-1;
            else s=mid+1;

            mid=s+(e-s)/2;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        //2Pointer
        /*
        int i=0;
        int j=numbers.size()-1;
        int sum;
        vector<int>ans;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum==target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }

            else if(sum>target) j--;

            else if(sum<target) i++;

        }
        return ans;
        */

        //Binary search

        int i=0;
        int n=numbers.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int req=target-numbers[i];
            int x=find(numbers,req,i+1,n-1);
            if(x!=-1){
                ans.push_back(i+1);
                ans.push_back(x+1);
                return ans;
            }
        }
        return ans;

        
    }
};