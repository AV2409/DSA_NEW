class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int diff=INT_MAX;
        vector<int>ans;
        //{ele,row,col}
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        multiset<tuple<int,int,int>>ms;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            ms.insert({nums[i][0],i,0});
        }
        while(pq.size()==n){
            auto [ele,row,col]=pq.top();
            pq.pop();
            auto [maxi,rm,cm]=*(prev(ms.end()));
            
            auto it=ms.find({ele,row,col});
            if(it!=ms.end()) ms.erase(it);
            if(maxi-ele<diff){
                ans={ele,maxi};
                diff=maxi-ele;
            }
            
            col++;
            if(col<nums[row].size()){
                pq.push({nums[row][col],row,col});
                ms.insert({nums[row][col],row,col});
            }
        }
        return ans;

    }
};