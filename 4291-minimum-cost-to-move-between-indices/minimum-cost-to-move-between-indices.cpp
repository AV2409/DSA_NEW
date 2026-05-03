class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long>back(n);
        vector<long long>front(n);

        front[1]=back[n-2]=1;

        for(int i=1;i<n-1;i++){
            int x=abs(nums[i]-nums[i-1]);
            int y=abs(nums[i]-nums[i+1]);

            if(y<x) front[i+1]=1+front[i];
            else front[i+1]=y+front[i];
        }

        for(int i=n-2;i>0;i--){
            int x=abs(nums[i]-nums[i-1]);
            int y=abs(nums[i]-nums[i+1]);

            if(x<=y) back[i-1]=1+back[i];
            else back[i-1]=x+back[i];
        }

        vector<int>ans;
        for(auto it:queries){
            int x=it[0];
            int y=it[1];

            if(x<=y){
                ans.push_back(front[y]-front[x]);
            }
            else{
                ans.push_back(back[y]-back[x]);
            }
        }
        return ans;
    }
};