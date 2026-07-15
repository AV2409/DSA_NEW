class Solution {
public:
    multiset<int>left;
    multiset<int>right;
    void balance(){
        if(left.size()>right.size()+1){
            int x=*(prev(left.end()));
            right.insert(x);
            left.erase(prev(left.end()));
        }
        if(right.size()>left.size()){
            int x=*(right.begin());
            left.insert(x);
            right.erase(right.begin());
        }
    }
    void add(int num){
        if(left.empty()||num<=*(prev(left.end()))) left.insert(num);
        else right.insert(num);

        balance();
    }

    void remove(int num){
        auto leftit=left.find(num);
        auto rightit=right.find(num);

        if(leftit!=left.end()){
            left.erase(leftit);
        }
        else right.erase(rightit);
        balance();
    }

    double median(){
        double x=*(prev(left.end()));
        if(left.size()==right.size()){
            double y=*(right.begin());
            return (x+y)/2.0;
        }
        else return x;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double>ans;

        for(int i=0;i<n;i++){
            add(nums[i]);
            if(i>=k){
                remove(nums[i-k]);
            }
            if(i>=k-1) ans.push_back(median());
        }
        return ans;
    }
};