class MinStack {
    stack<pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push({val,val});
        } else {
            auto top = s.top();
            if(val < top.second){
                s.push({val, val});
            } else {
                s.push({val,top.second});
            }
        }
    }
    
    void pop() {
        if(!s.empty())
            s.pop();
    }
    
    int top() {
        auto top = s.top();
        return top.first;
    }
    
    int getMin() {
        auto top = s.top();
        return top.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */