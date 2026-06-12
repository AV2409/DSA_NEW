class MedianFinder {
public:
    
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==right.size()){
            if(left.empty()) left.push(num);
            else if(left.top()>=num) left.push(num);
            else {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }

        else if(left.size()==right.size()+1){
            if(num>=left.top()) right.push(num);
            else {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        int n=left.size();
        int m=right.size();
        // cout<<left.top()<<" "<<right.top()<<endl;
        if((n+m)%2) return left.top();
        else return (left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */