class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        int l=left.size();
        int r=right.size();
        if(l-r>1){
            right.push(left.top());
            left.pop();
        }
        else{
            right.push(left.top());
            left.pop();
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int l=left.size();
        int r=right.size();
        if(l!=r) return left.top();
        else return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */