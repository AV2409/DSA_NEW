class Solution {
public:
    bool isPossible(long long num,int x){
        if(num%10!=x) return false;
        while(num/10){
            num=num/10;
        }
        if(num%10!=x) return false;
        return true;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(isPossible(sum,x)) ans++;
            }
        }
        return ans;
    }
};