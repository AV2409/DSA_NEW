class TrieNode{
    public:
    vector<TrieNode*>child;

    TrieNode(){
        child.assign(2,NULL);
    }
};

class Solution {
public:
    TrieNode* root=new TrieNode();
    void insert(string &word) {
        TrieNode* temp=root;
        for(char c:word){
            int idx=c-'0';
            if(temp->child[idx]==NULL){
                temp->child[idx]=new TrieNode();
            }
            temp=temp->child[idx];
        }
    }

    int find(string &word) {
        TrieNode* temp=root;
        int res=0;
        for(int i=0;i<32;i++){
            int idx=word[i]-'0';
            int inv=1-idx;
            if(temp->child[inv]){
                res<<=1;
                res|=1;
                temp=temp->child[inv];
            }
            else if(temp->child[idx]){
                res<<=1;
                temp=temp->child[idx];
            }
            else return -1;
        }
        return res;
    }
    string toBit(int num){
        string ans(32,'0');
        int idx=31;
        while(num>0){
            int dig=num&1;
            if(dig) ans[idx]='1';
            num>>=1;
            idx--;
        }
        return ans;
    }

    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int i=0;
        for(auto &q:queries){
            q.push_back(i);
            i++;
        }
        int ss=queries.size();
        vector<int>ans(ss,-1);

        vector<string>strs;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            strs.push_back(toBit(x));
        }

        sort(queries.begin(),queries.end(),comp);
        int idx=0;
        int n=nums.size();

        for(auto q:queries){
            int num=q[0];
            string strNum=toBit(num);
            int maxi=q[1];
            int k=q[2];

            while(idx<n && nums[idx]<=maxi){
                insert(strs[idx]);
                idx++;
            }

            int mm=find(strNum);
            ans[k]=mm;
        }
        return ans;

    }
};