class Solution {
public:
    
    int evaluate(int l, int r, char op) {
        switch(op){
            case '+':
                return l+r;
            case '/':
                return l/r;
            case '-':
                return l-r;
            case '*':
                return l*r;
        }
        return 0;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> left,right,results;
        bool isNumber = true;
        
        for(int i=0;i<expression.length();i++) {
            if(!isdigit(expression[i])) {
                if(isNumber)
                    isNumber = false;
                left = diffWaysToCompute(expression.substr(0,i));
                right = diffWaysToCompute(expression.substr(i+1));
                
                for(int l : left) {
                    for(int r: right) {
                        results.push_back(evaluate(l,r,expression[i]));
                    }
                }
            }
        }
        if(isNumber)
            return {stoi(expression)};
        return results;
    }
};