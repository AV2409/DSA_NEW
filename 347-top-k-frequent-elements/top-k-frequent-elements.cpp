class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }


        //{cnt,num}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto it:mp){
            int num=it.first;
            int cnt=it.second;

            pq.push({cnt,num});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            int x=pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};