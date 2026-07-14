class MinStack {
private:
    vector<int>minstack;
    vector<int>min;
public:
    MinStack() {    
    }
    
    void push(int val) {
        if(minstack.empty()){
            min.push_back(val);
        }
        else{
            if(val < min.back()) min.push_back(val);
            else{
                min.push_back(min.back());
            }
        }
        minstack.push_back(val);
    }
    
    void pop() {
        minstack.pop_back();
        min.pop_back();
    }
    
    int top() {
        return minstack.back();
    }
    
    int getMin() {
        return min.back();
    }
};
