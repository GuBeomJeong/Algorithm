class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
        left = priority_queue<int>();
        right = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        
        if(left.empty()){
            left.push(num);
            return;
        }
        
        if(num <= left.top()){
            left.push(num);
        }else{
            right.push(num);
        }
        
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }else if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        int n = left.size() + right.size();
        
        if(n%2){
            return (double)left.top();
        }else{
            return (double)(left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */