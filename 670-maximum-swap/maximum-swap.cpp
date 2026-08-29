class Solution {
public:
    bool static comp(pair<char,int>&a,pair<char,int>&b){
        return a.first>b.first;
    }
    int maximumSwap(int num) {
        string n=to_string(num);
        
        int ss=n.size();
        vector<pair<char,int>>v(ss);
        v[ss-1]={n[ss-1],ss-1};
        for(int i=ss-2;i>=0;i--){
            auto [maxi,idx]=v[i+1];
            if(maxi>=n[i]){
                v[i]={maxi,idx};
            }
            else{
                v[i]={n[i],i};
            }
        }

        for(int i=0;i<ss;i++){
            if(n[i]<v[i].first){
                int idx=v[i].second;
                swap(n[i],n[idx]);
                break;
            }
        }
        int ans=stoi(n);
        return ans;

    }
};