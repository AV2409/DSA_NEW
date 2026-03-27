class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<m;i++){
            int j;
            for(j=0;j<n;j++){
                if(mat[i][j]==0) break;
            }
            int ones=j;
            pq.push({ones,i});

            if(pq.size()>k) pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};