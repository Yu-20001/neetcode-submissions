class MedianFinder {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!lower.empty() && num > lower.top()){
            upper.push(num);
            if(upper.size() > lower.size()){
                int temp = upper.top();
                upper.pop();
                lower.push(temp);
            }
        }
        else{
            lower.push(num);
            if(lower.size() - upper.size() > 1){
                int temp = lower.top();
                lower.pop();
                upper.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(lower.size() == upper.size()){
            return ((double)lower.top() + (double)upper.top()) / 2;
        } 
        else{
            return (double)lower.top();
        }
    }
};
