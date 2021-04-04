class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> numStack;
    stack<int> minStack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty()) {
            minStack.push(val);
        } else {
        if(val < minStack.top()) 
            minStack.push(val);
        else
            minStack.push(minStack.top());
        }
        numStack.push(val);
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
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