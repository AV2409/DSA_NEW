class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()||num<=left.top()){
            left.push(num);
        }
        else right.push(num);

        int l=left.size();
        int r=right.size();

        if(l>r+1){
            right.push(left.top());
            left.pop();
        }
        if(r>l){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int l=left.size();
        int r=right.size();

        if((l+r)%2) return left.top();
        return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */