class Solution {
public:
    int N;
    int K;
    vector<vector<int>> ans;
    vector<int> list;
    void helper(int i) {
        if (list.size() > K)
            return;
        if (i > N) {
            if (list.size() == K)
                ans.push_back(list);
            return;
        }

        // pick

        list.push_back(i);
        helper(i + 1);
        list.pop_back();

        
        helper(i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        helper(1);
        return ans;
    }
};