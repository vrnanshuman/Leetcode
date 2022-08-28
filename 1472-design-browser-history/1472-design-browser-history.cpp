class BrowserHistory {
    list<string> pageStack;
    list<string>::iterator cursor;
public:
    BrowserHistory(string homepage) {
        pageStack.push_front(homepage);
        cursor = pageStack.begin();
    }
    
    void visit(string url) {
        pageStack.erase(next(cursor,1), pageStack.end());
        pageStack.push_back(url);
        cursor = next(cursor,1);
    }
    
    string back(int steps) {
        int backSteps = distance(pageStack.begin(), cursor);
        if(backSteps < steps) {
            cursor = pageStack.begin();
            return *cursor;
        }
        cursor = prev(cursor, steps);
        return *cursor;
    }
    
    string forward(int steps) {
        int forwardSteps = distance(cursor,pageStack.end())-1;
        if(forwardSteps < steps) {
            cursor = prev(pageStack.end(),1);
            return *cursor;
        }
        cursor = next(cursor, steps);
        return *cursor;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */