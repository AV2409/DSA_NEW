class Solution {
public:
    vector<int>cols;
    int N;
    int ans=0;
    bool isPossible(int r,int c){
        int ss=cols.size();
        for(int i=0;i<ss;i++){
            int row=i;
            int col=cols[i];

            if(c==col || abs(row-r)==abs(col-c)) return false;
        }
        return true;
    }
    void helper(int r){
        if(r==N){
            ans++;
            return;
        }

        for(int c=0;c<N;c++){
            if(isPossible(r,c)){
                cols.push_back(c);
                helper(r+1);
                cols.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        N=n;
        helper(0);
        return ans;
    }
};