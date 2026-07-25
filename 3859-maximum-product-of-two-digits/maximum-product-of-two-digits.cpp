class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>>pq;
        while(n>0){
            int dig=n%10;
            pq.push(dig);
            if(pq.size()>2) pq.pop();
            n/=10;
        }
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        return x*y;
    }
};