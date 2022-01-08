class Solution {
public:
    int calculate(string str) {
        int currentNum = 0;
        char sign = '$';
        stack<int> s;
        
        for(char c : str) {
            if(c == ' ')
                continue;
            if(isdigit(c)) {
                currentNum  = currentNum*10 + (c-'0');
            } else {
                if(sign == '$' || sign == '+')
                    s.push(currentNum);
                else if(sign == '-') 
                    s.push(-1*currentNum);
                else {
                    int n1 = s.top();
                    s.pop();
                    sign == '*' ? s.push(n1*currentNum) : s.push(n1/currentNum);
                }
                currentNum = 0;
                sign = c;
            }
        }
        if(sign == '$' || sign == '+')
            s.push(currentNum);
        else if(sign == '-') 
            s.push(-1*currentNum);
        else {
            int n1 = s.top();
            s.pop();
            sign == '*' ? s.push(n1*currentNum) : s.push(n1/currentNum);
        }
        int result = 0;
        while(!s.empty()) {
            result+=s.top();
            s.pop();
        }
        return result;
    }
};