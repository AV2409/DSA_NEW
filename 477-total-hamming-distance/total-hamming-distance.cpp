class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int>setbits(32,0);

        for(int x:nums){
            int i=31;
            while(x){
                int bit=x&1;
                setbits[i]+=bit;
                x>>=1;
                i--;
            }
        }
        int ans=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            // cout<<setbits[i]<<" ";
            ans+=(setbits[i])*(n-setbits[i]);
        }
        return ans;

        
    }
};