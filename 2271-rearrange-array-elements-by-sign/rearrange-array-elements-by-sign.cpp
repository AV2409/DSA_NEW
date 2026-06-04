class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>pos;
        queue<int>neg;

        for(int x:nums){
            if(x<0) neg.push(x);
            else pos.push(x);
        }

        bool flag=true;
        vector<int>ans;
        while(!pos.empty() || !neg.empty()){
            if(flag){
                ans.push_back(pos.front());
                pos.pop();
            }

            else{
                ans.push_back(neg.front());
                neg.pop();
            }
            flag=!flag;
        }
        return ans;
    }
};