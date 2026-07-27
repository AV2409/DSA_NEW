class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
       vector<vector<int>>ans;
       int n1=series1.size();
       int n2=series2.size();

       int i=0;
       int j=0;

       while(i<n1 && j<n2){
        int ti=series1[i][0];
        int vi=series1[i][1];

        int tj=series2[j][0];
        int vj=series2[j][1];

        if(ti==tj){
            ans.push_back({ti,vi+vj});
            i++;
            j++;
        }
        else if(ti<tj){
            ans.push_back({ti,vi+vj});
            i++;
        }
        else{
            ans.push_back({tj,vi+vj});
            j++;
        }
       } 

       while(i<n1){
        int ti=series1[i][0];
        int vi=series1[i][1];

        ans.push_back({ti,vi});
        i++;
       }

       while(j<n2){
        int tj=series2[j][0];
        int vj=series2[j][1];

        ans.push_back({tj,vj});
        j++;
       }
       return ans;
    }
};