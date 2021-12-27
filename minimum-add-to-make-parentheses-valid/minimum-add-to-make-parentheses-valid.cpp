class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> bStack;
        int count=0;
        
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(')
                bStack.push(s[i]);
            else {
                if(bStack.empty()) {
                    count++;
                } else {
                    bStack.pop();
                }
            }
        }
        while(!bStack.empty()) {
            count++;
            bStack.pop();
        }
        return count;
        
    }
};