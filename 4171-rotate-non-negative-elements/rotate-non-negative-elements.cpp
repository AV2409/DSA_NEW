class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        queue<int>q;
        int n=nums.size();
        vector<bool>z(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                q.push(nums[i]);
                z[i]=true;
                cnt++;
            }
        }

        if(cnt==0) return nums;
        k %= cnt;
        while(k--){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }

        for(int i=0;i<n;i++){
            if(z[i]){
                nums[i]=q.front();
                q.pop();
            }
        }
        return nums;
    }
};