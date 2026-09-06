class Solution {
public:
    string getPermutation(int n, int k) {
        //find n-1 fact
        vector<int>arr;
        int fact=1;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
            fact=fact*i;
        }

        // arr.push_back(n);
        k--;
        string ans="";
        while(arr.size()>0){
            int nn=arr.size();
            fact=fact/nn;
            int idx=k/fact;
            ans+=to_string(arr[idx]);
            k=k%fact;
            arr.erase(arr.begin()+idx);
        }
        return ans;
    }
};