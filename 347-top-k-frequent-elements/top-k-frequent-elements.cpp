class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x:nums) mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp){
            int num=it.first;
            int cnt=it.second;

            pq.push({cnt,num});
            if(pq.size()>k) pq.pop();
            
        }

        vector<int>ans;

        while(!pq.empty()){
            int num=pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};